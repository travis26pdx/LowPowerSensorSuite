#ifndef SDCARD_h
#define SDCARD_h

#include "Jaffl.h"
#define SENSOR_TEMP     1
#define SENSOR_HUMI     2
#define SENSOR_NO2      3
#define SENSOR_CO2      4
#define SENSOR_O2       5
#define SENSOR_WATER    6

void initSDCard(void);
void SDwrite(unsigned char mode, float value,unsigned long time);
#endif
