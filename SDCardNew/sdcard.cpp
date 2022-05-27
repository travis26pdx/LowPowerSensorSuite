#include "sdcard.h"
String TempDir = "Temp";
String HumiDir = "Humi";
String NO2Dir = "NO2";
String CO2Dir = "CO2";
String O2Dir = "O2";
String WaterDir = "Water";

String TempFile = "temp01.csv";
String HumiFile = "humi01.csv";
String NO2File = "NO201.csv";
String CO2File = "CO201.csv";
String O2File = "O201.csv";
String WaterFile = "Water01.csv";
void initSDCard(void)
{
  Serial.print("Begin, return code: ");
  while(Jaffl.begin(P4_0)!=0){
    Serial.println("Unable to mount SD card");
    delay(500);
  }
  Serial.println("SD card succesfully mounted");
}
void SDwrite(unsigned char mode, float value, unsigned long time)
{
  String folder,filename,filepath,datastring;
  FIL file;
  switch (mode)
  {
    case SENSOR_TEMP:{ // SENSOR_TEMP
      folder = TempDir;
      filename = TempFile;
      filepath = folder + "/" + filename;
      datastring = String(value,2) + "," + String(time) + "\r\n";
    }break;
    case SENSOR_HUMI:{ // SENSOR_HUMI
      folder = HumiDir;
      filename = HumiFile;
      filepath = folder + "/" + filename;
      datastring = String(value,2) + "," + String(time) + "\r\n";
    }break;
    case SENSOR_NO2:{ // SENSOR_NO2
      folder = NO2Dir;
      filename = NO2File;
      filepath = folder + "/" + filename;
      datastring = String(value,2) + "," + String(time) + "\r\n";
    }break;
    case SENSOR_CO2:{ // SENSOR_CO2
      folder = CO2Dir;
      filename = CO2File;
      filepath = folder + "/" + filename;
      datastring = String(value,2) + "," + String(time) + "\r\n";
    }break;
    case SENSOR_O2:{ // SENSOR_O2
      folder = O2Dir;
      filename = O2File;
      filepath = folder + "/" + filename;
      datastring = String(value,2) + "," + String(time) + "\r\n";
    }break;
    case SENSOR_WATER:{ // SENSOR_WATER
      folder = WaterDir;
      filename = WaterFile;
      filepath = folder + "/" + filename;
      datastring = String(value,2) + "," + String(time) + "\r\n";
    }break;
    default:break;
  }
  if (Jaffl.opendir(folder.c_str()) == FR_NO_PATH) {
    Jaffl.mkdir(folder.c_str());
  }
  if (Jaffl.open(&file,filepath.c_str(), FA_WRITE) == FR_NO_FILE) {
    Jaffl.open(&file,filepath.c_str(), FA_WRITE | FA_CREATE_NEW);
  }
  else
  {
    Jaffl.open(&file,filepath.c_str(), FA_WRITE);
    Jaffl.endseek(&file);  //while in else part, file has been opened
  }
  Jaffl.printf(&file, datastring.c_str());
  Jaffl.sync(&file);
  delay(100);
  Jaffl.close(&file);
}
