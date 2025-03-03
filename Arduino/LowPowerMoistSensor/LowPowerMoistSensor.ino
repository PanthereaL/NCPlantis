#include "sensors.h"
#include "display_config.h"
#include "buttons.h"
#include "reset.h"
#include "buttons.h"

unsigned long lastPoll;
unsigned long sensorInterval = 600000; //10 minutes

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initiate_sensors();
  initiate_display();
  setup_reset();
  initiate_buttons();

  lastPoll = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  //Only run the sensor if it's being read from.
  if (currentMillis - lastPoll > sensorInterval) {
    Sensors::turn_on(0);
    delay(200); // To make sure the sensor has time to properly turn on
    Sensors::poll();
    //I forgot how to send a line over serial TODO
    Sensors::turn_off(0);
  }

  //Poll the button every loop
  Buttons::poll();
  if (buttonState) {
    Display::turn_on();
    update_display("Moisture Level:", String(moistureLevel1));
    while(currentMillis + displayDelay > millis()) {} //Leave the screen on
    Display::turn_off();
  }
}
