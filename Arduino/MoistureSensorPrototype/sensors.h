#ifndef SENSORS_H
#define SENSORS_H

/*Purpose:
 *The project thus far has six sensors, light, water level and four
 *moisture sensors. This is the interface with them. */

//Variables
//extern int waterLevel;

extern int moistureLevel1;
//moistureLevel2,
//moistureLevel3,
//moistureLevel4;

//extern int lightLevel;

//Functions
void initiate_sensors();
namespace Sensors {
void poll(); //Polls all the sensors to update the values.
}
#endif