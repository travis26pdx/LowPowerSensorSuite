#include <Wire.h>
#include <IpMtWrapper.h>
#define HIH8120Addr         0x27                      //I2C Addr
#define HIH8120Cmd          0xFF                      //HandShake Cmd
#define BytesToRead         4                         //Lens of Read Bytes 
#define SampleNums          1                        //Total Sample Nums
#define SampleInterval      100                       //Ms
#define MeasureInterval     0.1 * 100000               //Measure every 10sec
unsigned long MeasureTime = 0;                        //Interval Between Last SampleNums And Now SampleNums
unsigned long SampleTime = 0;                         //Sample Interval
int SampleCounts = 0;                                 //Current Sample Counter
/* Humiture */
float HumiVals[SampleNums];                           //Store History Humi Data
float TempVals[SampleNums];
float HumiSum = 0;                                    //Store History Humi Sum
float TempSum = 0;
float HumiAvg = 0;                                    //Calculate Average According to Humi Sum 
float TempAvg = 0;
float Humi,Temp;                                    //Humi (%) and Temp (C)
int tempHumiCollect, tempTransfer, humiTransfer;

IpMtWrapper       ipmtwrapper;

//============================== data generator ==================================
void generateData(uint16_t* returnVal) {
 if (tempHumiCollect) {                                              //If tempHumiCollect = 1 then call function to get temp and humid data from sensor
     GetHIHSensor();
     tempHumiCollect = 0;                                            //Stop collection of temp and humid
 }
 if (tempTransfer) {                                                 //If temp data is ready to be transferred via smartmesh
     Serial.print("Temp: ");Serial.print(Temp);Serial.println("C");
     returnVal[0] = (int)(Temp * 100);                               //Temp is a float value so multiply by 100 to get rid of decimal points and also cast float as int
     tempTransfer = 0;                                               //Stop transfer of temp data
     return;
 }
 if (humiTransfer) {                                                 //If humid data is ready to be transferred via smartmesh
     Serial.print("Humi: ");Serial.print(Humi);Serial.println("%");
     returnVal[0] = (int)(Humi * 100);                               //Humid is a float value so multiply by 100 to get rid of decimal points and also cast float as int
     humiTransfer = 0;                                               //Stop transfer of humid data
 }
 tempHumiCollect = 1;                                                //Value to start collecting temp and humid data
}

void setup() {                                        //put your setup code here, to run once:
  ipmtwrapper.setup(
      60000,                           // srcPort
      (uint8_t*)ipv6Addr_manager,      // destAddr
      61000,                           // destPort
      300,                           // dataPeriod (ms)
      generateData                     // dataGenerator
  );
  Serial.begin(9600);                                //Init Serial
  Wire.begin();                                       //I2C Begin
  //Serial.println("System Ready!");
}

void loop() {
  // put your main code here, to run repeatedly:
    ipmtwrapper.loop();
  //if(millis() - MeasureTime >= MeasureInterval){      //Conduct a new round of sampling Timer
  //  MeasureTime = millis();                           //Reset Timer
  //  SampleCounts = 0;                                 //Reset SampleCounter
  //  GetHIHSensor();
  //}
}


void GetHIHSensor(){
  byte HIHdata[4];                                    //Store Data Read
  byte HIHstatus = 0;                                 //Sensor Status
  int Reading;                                        //Convert Data Read
  //float Humi,Temp;                                    //Humi (%) and Temp (C)
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
  tempTransfer = 1;                                   //tempTransfer is set to 1 since temp data is ready to be transferred via smartmesh
  humiTransfer = 1;                                   //humidTransfer is set to 1 since humid data is ready to be transferred via smartmesh
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
