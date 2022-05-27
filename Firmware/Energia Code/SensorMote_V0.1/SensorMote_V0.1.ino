#include <Wire.h>
#include <IpMtWrapper.h>
#include "sdcard.h"
#define N2OSerial Serial2
#define HIH8120Addr         0x27                      //I2C Addr
#define HIH8120Cmd          0xFF                      //HandShake Cmd
#define BytesToRead         4                         //Lens of Read Bytes 
#define SampleNums          1                         //Total Sample Nums
#define SampleInterval      100                       //Ms
#define MeasureIntervalTemp     60000                 //Measure every 60sec (60000ms) 1 minute
#define MeasureIntervalHumi     120000                //Measure every 120sec (120000ms) 2 minutes
#define MeasureIntervalN2O      600000                //Measure every 600sec (600000ms) 10 minutes
unsigned long MeasureTimeTemp = 0;                    //Interval Between Last SampleNums And Now SampleNums
unsigned long MeasureTimeHumi = 0;
unsigned long MeasureTimeN2O = 0;
unsigned long MeasureTimeN2OMinus1Minute = 0;
unsigned long SampleTime = 0;                         //Sample Interval
int SampleCounts = 0;                                 //Current Sample Counter
/* Humiture */
float HumiVals[SampleNums];                           //Store History Humi Data
float TempVals[SampleNums];
float HumiSum = 0;                                    //Store History Humi Sum
float TempSum = 0;
float HumiAvg = 0;                                    //Calculate Average According to Humi Sum 
float TempAvg = 0;
float Humi,Temp;                                      //Humi (%) and Temp (C)
bool dataSent = false;                                //Used to determine if MCU should go into sleep mode
byte N2OCmd[7] = {0x10,0x13,0x06,0x10,0x1F,0x00,0x58};
byte N2ORece[15];
float N2OData;
int minuteNine = 1;

IpMtWrapper       ipmtwrapper;

//============================== data generator ==================================
void generateData(uint16_t* returnVal) {
     returnVal[0] = 65535;                                       //Missing data filled with 65535 instead of 0 because 0 is valid data for N2O. Tried using -1 before but uint16_t data type only goes from 0 to 65535.
     returnVal[1] = 65535;
     returnVal[2] = 65535;
     if (millis() - MeasureTimeTemp >= MeasureIntervalTemp) {    //Measure temperature every 1 minute
         MeasureTimeTemp = millis();                             //Reset Timer
         GetHIHSensor();
         returnVal[0] = (int)(Temp * 100);                       //Values multiplied by 100 because only integers can be sent via SmartMesh
         SDwrite(SENSOR_TEMP, Temp, millis());
     }
     if (millis() - MeasureTimeHumi >= MeasureIntervalHumi) {    //Measure humidity every 2 minutes
         MeasureTimeHumi = millis();                             //Reset Timer
         returnVal[1] = (int)(Humi * 100);
         SDwrite(SENSOR_HUMI, Humi, millis());
     }
     if (millis() - MeasureTimeN2OMinus1Minute >= (MeasureIntervalN2O - 60000) && minuteNine) { //Sample rate of N2O minus 1 minute
         MeasureTimeN2OMinus1Minute = millis();                  //Reset Timer
         digitalWrite(P4_3, HIGH);                               //Apply 3.3V to gate of transistor
         minuteNine = 0;
     }
     if (millis() - MeasureTimeN2OMinus1Minute >= MeasureIntervalN2O) {
         MeasureTimeN2OMinus1Minute = millis();                  //Reset Timer
         digitalWrite(P4_3, HIGH);                               //Apply 3.3V to gate of transistor
     }
     if (millis() - MeasureTimeN2O >= MeasureIntervalN2O) {      //Measure N2O every 10 minutes
         MeasureTimeN2O = millis();                              //Reset Timer
         N2OGet();
         returnVal[2] = (int)(N2OData * 100);
         digitalWrite(P4_3, LOW);                                //Apply 0V to gate of transistor
         SDwrite(SENSOR_NO2, N2OData, millis());
     }
     dataSent = true;
}

void setup() {                                        //put your setup code here, to run once:
  ipmtwrapper.setup(
      60000,                                          // srcPort
      (uint8_t*)ipv6Addr_manager,                     // destAddr
      61000,                                          // destPort
      100,                                            // dataPeriod (ms)
      generateData                                    // dataGenerator
  );
  Serial.begin(9600);                                 //Init Serial
  Wire.begin();                                       //I2C Begin
  initSDCard();                                       //Init SD Card
  N2OSerial.begin(38400);
  pinMode(P4_3, OUTPUT);                              //Set P4_3 to be an output
  digitalWrite(P4_3, LOW);                            //Must set P4_3 to low (0V) when defining pin mode for P4_3 because it will output logic level high (3.3V) by default.
}

void loop() {
  // put your main code here, to run repeatedly:
  if (dataSent == true) {
      sleep(60000);                                  //Have MCU sleep for 60 seconds after data has been sent
  }
  dataSent = false;
  ipmtwrapper.loop();
}

void GetHIHSensor(){
  byte HIHdata[4];                                    //Store Data Read
  byte HIHstatus = 0;                                 //Sensor Status
  int Reading;                                        //Convert Data Read
  //float Humi,Temp;                                  //Humi (%) and Temp (C)
  Wire.beginTransmission(HIH8120Addr);                //I2C HandShake
  Wire.write(HIH8120Cmd);
  Wire.endTransmission();
  delay(50);                                          //Wait for Sensor Prepare Data (50 ms Delay(~36.65 ms))
  Wire.requestFrom(HIH8120Addr, BytesToRead);         //Read 4 Bytes Data
  HIHdata[0] = Wire.read();
  HIHdata[1] = Wire.read();
  HIHdata[2] = Wire.read();
  HIHdata[3] = Wire.read();
  HIHstatus = HIHdata[0] & 0b11000000;                //Get Sensor Status
  if (HIHstatus != 0) {
    Serial.println("Status Bits Error!");
    //return 1;
  }
  /* Humidity is located in first two bytes */
  Reading = 0;
  Reading = HIHdata[0] << 8;                          //High 8 bits Data of Humi
  Reading |= HIHdata[1];                              //Combine High 8 bits and Low 8 bits Data
  Humi = float(Reading) / 16382.0 * 100.0;            //Convert it to Real Value: Reading/(2^14-2)*100
  /* Temperature is located in next two bytes, padded by two trailing bits */
  Reading = 0;
  Reading = HIHdata[2] << 6;                          //Only the first 6 bits of data are valid, and the remaining 2 bits are filled bits
  Reading |= (HIHdata[3] >> 2);
  Temp = float(Reading) / 16382.0 * 165.0 - 40;       //Convert it to Real Value: Reading/(2^14-2)*100
  /* Add Current Values To Array */
  HumiVals[SampleCounts] = Humi;
  TempVals[SampleCounts] = Temp;
}

void N2OGet(){
  N2OSerial.write(N2OCmd,7);
  delay(1000);
  if(N2OSerial.available()){
    byte recebyte = N2OSerial.read();
    Serial.print(recebyte, HEX);
    Serial.print("|");
    if(recebyte == 0x10){
      N2ORece[0] = 0x10;
      int i;
      int m = 0;
      char ReadArray[4];
      bool flag;
      while (N2OSerial.available()){
        flag = false;
        for(i = 1;i < 15;i++){
          N2ORece[i] = N2OSerial.read();
          Serial.print(N2ORece[i], HEX);
          Serial.print("|");
          if(i >= 7 && i <= 10){
            ReadArray[m++] = N2ORece[i];
          }
        }
        Serial.println();
        N2OData = *(float*)ReadArray;
        N2OData = N2OData / 10;
        Serial.print("N2O Data is: ");
        Serial.print(N2OData);
        Serial.println("ppm");
        if(N2OData == -2500){
          Serial.println("N2O Sensor Warmup!");
        }
      }
    }
  } 
}

void CalculateAvg(){
  /* Humiture */
  HumiAvg = HumiSum / float(SampleNums);              //Calculate Humi Average 
  TempAvg = TempSum / float(SampleNums);              //Calculate Temp Average 
  HumiSum = 0;
  TempSum = 0;
  Serial.print("Humi Avg:\t");Serial.print(HumiAvg);Serial.println("%");
  Serial.print("Temp Avg:\t");Serial.print(TempAvg);Serial.println("C");
}
