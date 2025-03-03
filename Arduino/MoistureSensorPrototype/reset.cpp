#include "Arduino.h"
#include "reset.h"

//External Variables

//Internal variables
static unsigned long startMillis;
static const unsigned long resetInterval = 86400000; // 24h in ms

//Functions
void setup_reset() {
  startMillis = millis();
}

void reset_arduino() {
  asm volatile("  jmp 0"); // Assembly instruction to start over
}

void check_reset() {
  unsigned long currentMillis = millis();

  if(currentMillis - startMillis >= resetInterval) {
    reset_arduino();
  }
}