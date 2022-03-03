#include "SPI.h"
#include "Jaffl.h"

int counter = 0;

void setup()
{
  Serial.begin(57600);
  Serial.println("Startup");
  Serial.print("Begin, return code: ");
  Serial.println(Jaffl.begin(P3_0));    
  Serial.print("Open file, return code: ");
  Serial.println(Jaffl.open("test.txt", FA_WRITE | FA_CREATE_ALWAYS));
}

void loop()
{
  Serial.print("Print file, return code: ");
  Serial.println(Jaffl.printf("Hello world: %d\r\n", counter++));
  Serial.print("Sync, return code: ");
  Serial.println(Jaffl.sync());
  delay(1000);
}
