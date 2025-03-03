#include "Arduino.h"
#include "logic.h"
#include "sensors.h"
#include "motors.h"

//External Variables

//Internal Variables
static const long delayTime = 600000;
static unsigned long lastEval = 0;
static int moistureLevelThreshold = 300;

//Functions
void do_logic() {
  unsigned long curTime = millis();
  if (curTime > lastEval + delayTime) {
    lastEval = curTime;
    /* Mmh, yes, if the moisture sensor was also arranged like a list,
     * it would be much easier to line the motors up with them in one
     * neat little for loop, but I can't do that right now. TODO */
    if (moistureLevel1 < moistureLevelThreshold) {
      motorStates[0] = HIGH;
    }
    if (moistureLevel2 < moistureLevelThreshold) {
      motorStates[1] = HIGH;
    }
    if (moistureLevel3 < moistureLevelThreshold) {
      motorStates[2] = HIGH;
    }
    if (moistureLevel4 < moistureLevelThreshold) {
      motorStates[3] = HIGH;
    }
  }
}