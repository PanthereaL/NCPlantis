//Includes to the project:
#include "pin_define.h"
#include "sensors.h"
#include "display_config.h"
#include "reset.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initiate_sensors();
  initiate_display();
  setup_reset();
}

void loop() {
  // put your main code here, to run repeatedly:
  Sensors::poll();
  update_display("Moisture Level:", String(moistureLevel1));
  delay(5000);
}
