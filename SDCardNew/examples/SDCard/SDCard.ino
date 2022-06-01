#include "sdcard.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initSDCard();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Data Write");
  SDwrite(1,random(1001)/1000.0,millis());
  SDwrite(2,random(1001)/1000.0,millis());
  SDwrite(3,random(1001)/1000.0,millis());
  SDwrite(4,random(1001)/1000.0,millis());
  SDwrite(5,random(1001)/1000.0,millis());
  SDwrite(6,random(1001)/1000.0,millis());
  delay(2000);
}