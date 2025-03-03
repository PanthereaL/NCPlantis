#include "Arduino.h"
#include "motors.h"
#include "pin_define.h"

//External variables
int motorStates[4] = { LOW, LOW, LOW, LOW };
// I'm pretty sure there's an easier way to write all zeroes.

//Internal variables
static const long delayTime = 600000;
static unsigned long lastEval = 0;

//Functions
void initiate_motors() {
  for (int i = 0; i < 4; i++) { //TODO: reference amount of motors
    pinMode(MOTOR_PINS[i], OUTPUT);
  }
}

void evaluate_motors() {
  /* Because this is the motors for the pumps, their function is very
   * simple. They have to turn on if they have been told they need to
   * be on, run for a little while, and then turn off.
   */
  unsigned long curTime = millis();
  if (curTime > lastEval + delayTime) {
    lastEval = curTime;
    for (int i = 0; i < 4; i++) {
      digitalWrite(MOTOR_PINS[i], motorStates[i]);
      /* This could probably be more efficient if I ask if motorStates[i]
       * is high before telling it to write to the motor, but taking 
       * the extra microsecond to write a LOW state to a motor that is
       * supposed to remain low doesn't hurt.
       */
      motorStates[i] = LOW;
    }
    delay(1000);
    for (int i = 0; i < 4; i++) {
      digitalWrite(MOTOR_PINS[i], LOW);
    }
  }
}