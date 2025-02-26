#ifndef PIN_DEFINE_H
#define PIN_DEFINE_H

/* Purpose:
 * These are the pin names to be used in other functions.
 * If you make changes, make sure to check that you don't break anything,
 * and that you update properly. */

//Button pins
extern const int BUTTON_PIN;

//Sensor pins
extern const int
WATER_SENSOR_PIN,
MOIST_SENSOR_PIN1,
MOIST_SENSOR_PIN2,
MOIST_SENSOR_PIN3,
MOIST_SENSOR_PIN4,
LIGHT_SENSOR_PIN;

//Motor pins
extern const int MOTOR_PINS[];

//Relay pins
extern const int RELAY_PIN;

#endif