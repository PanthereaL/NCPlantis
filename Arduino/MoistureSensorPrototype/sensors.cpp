#include "Arduino.h"
#include "sensors.h"
#include "pin_define.h"
//TODO: Rework to be entirely modular

//External variables
//int waterLevel = 0;

int moistureLevel1 = 0;
  //moistureLevel2 = 0;
  //moistureLevel3 = 0;
  //moistureLevel4 = 0;

//int lightLevel = 0;

//Internal variables
//static const long delayTime = 600000;  //600,000 milliseconds makes for 10 minutes.
//static unsigned long lastRead = 0;

//Functions
void initiate_sensors() {
  //Analogue pins do not have to be set up the same way digital pins
  //do, but the starting values are noted.
  //TODO make the sensor pins also handled by loops
  //waterLevel = analogRead(WATER_SENSOR_PIN);
  moistureLevel1 = analogRead(MOIST_SENSOR_PIN[0]);
  //moistureLevel2 = analogRead(MOIST_SENSOR_PIN[1]);
  //moistureLevel3 = analogRead(MOIST_SENSOR_PIN[2]);
  //moistureLevel4 = analogRead(MOIST_SENSOR_PIN[3]);
  //lightLevel = analogRead(LIGHT_SENSOR_PIN);
}

namespace Sensors {
void poll() {  //Reads the sensor values
    //waterLevel = analogRead(WATER_SENSOR_PIN);
    moistureLevel1 = analogRead(MOIST_SENSOR_PIN[0]);
    //moistureLevel2 = analogRead(MOIST_SENSOR_PIN2);
    //moistureLevel3 = analogRead(MOIST_SENSOR_PIN3);
    //moistureLevel4 = analogRead(MOIST_SENSOR_PIN4);
    //lightLevel = analogRead(LIGHT_SENSOR_PIN);
  }
}
