#include "Arduino.h"
#include "buttons.h"
#include "pin_define.h"

//External variables
int buttonState = 0;

//Internal variables
static unsigned long lastPress = 0;  // This is to help calculate the debounce
static const int debounce = 20;      // In milliseconds

void initiate_buttons() {
  pinMode(BUTTON_PIN, INPUT);
  buttonState = digitalRead(BUTTON_PIN);
}

namespace Buttons {
void poll() {
  unsigned long curTime = millis();
  int reading = digitalRead(BUTTON_PIN);

  if (reading != buttonState) {
    if (curTime - lastPress > debounce) {
      lastPress = curTime;
      buttonState = reading;
    }
  }
}
}