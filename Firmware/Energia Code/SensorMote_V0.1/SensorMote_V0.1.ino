#include <Wire.h>
#include <IpMtWrapper.h>
#define HIH8120Addr         0x27                      //I2C Addr
#define HIH8120Cmd          0xFF                      //HandShake Cmd
#define BytesToRead         4                         //Lens of Read Bytes 
#define SampleNums          1                         //Total Sample Nums
#define SampleInterval      100                       //Ms
#define MeasureIntervalTemp     0.1 * 100000          //Measure every 10sec
#define MeasureIntervalHumi     0.2 * 100000          //Measure every 20sec
#define MeasureIntervalN2O      0.3 * 100000          //Measure every 30sec
unsigned long MeasureTimeTemp = 0;                    //Interval Between Last SampleNums And Now SampleNums
unsigned long MeasureTimeHumi = 0;
unsigned long MeasureTimeN2O = 0;
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

IpMtWrapper       ipmtwrapper;

//============================== data generator ==================================
void generateData(uint16_t* returnVal) {
     if (millis() - MeasureTimeTemp >= MeasureIntervalTemp) {    //Measure temperature every 10 seconds
         MeasureTimeTemp = millis();                             //Reset Timer
         GetHIHSensor();
         returnVal[0] = (int)(Temp * 100);
         returnVal[1] = 0;
         returnVal[2] = 0;
     }
     if (millis() - MeasureTimeHumi >= MeasureIntervalHumi) {    //Measure humidity every 20 seconds
         MeasureTimeHumi = millis();                             //Reset Timer
         returnVal[1] = (int)(Humi * 100);
         returnVal[2] = 0;
     }
     if (millis() - MeasureTimeN2O >= MeasureIntervalN2O) {      //Measure N2O every 30 seconds
         MeasureTimeN2O = millis();                              //Reset Timer
         returnVal[2] = 1000;                                    //Placeholder value for N2O
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
}

void loop() {
  // put your main code here, to run repeatedly:
  if (dataSent == true) {
      sleep(10000);                                  //Have MCU sleep for 10 seconds after data has been sent
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


void CalculateAvg(){
  /* Humiture */
  HumiAvg = HumiSum / float(SampleNums);              //Calculate Humi Average 
  TempAvg = TempSum / float(SampleNums);              //Calculate Temp Average 
  HumiSum = 0;
  TempSum = 0;
  Serial.print("Humi Avg:\t");Serial.print(HumiAvg);Serial.println("%");
  Serial.print("Temp Avg:\t");Serial.print(TempAvg);Serial.println("C");
}
