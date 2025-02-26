#include "Arduino.h"
#include "pin_define.h"

/* Purpose:
 * Here the pin names are given their actual values. Update here if
 * changes to the hardware are made. */

//Button pins
const int BUTTON_PIN = 8;

//Sensor pins
const int
WATER_SENSOR_PIN = A0,
MOIST_SENSOR_PIN1 = A1,
MOIST_SENSOR_PIN2 = A2,
MOIST_SENSOR_PIN3 = A3,
MOIST_SENSOR_PIN4 = A4,
LIGHT_SENSOR_PIN = A5;

//Motor pins
const int MOTOR_PINS[] = {2, 3, 4, 5};

//Relay pins
const int RELAY_PIN = 7;

//LCD pins
//TODO