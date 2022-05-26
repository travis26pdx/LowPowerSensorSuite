#define N2OSerial Serial2
byte N2OCmd[7] = {0x10,0x13,0x06,0x10,0x1F,0x00,0x58};
byte N2ORece[15];
float N2OData;
void setup() {
  Serial.begin(9600);
  N2OSerial.begin(38400);
}
void loop() {
  sleep(15000);
  N2OGet();
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
