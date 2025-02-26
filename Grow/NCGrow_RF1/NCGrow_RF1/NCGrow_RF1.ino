//Includes to the project:
//#include 
#include "buttons.h"
#include "sensors.h"
#include "motors.h"
#include "display_config.h"
#include "reset.h"
#include "logic.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initiate_buttons();
  initiate_sensors();
  initiate_motors();
  initiate_display();
  setup_reset();
  welcome_to_grow();
}

void loop() {
  Buttons::poll();
  /* TODO: Implement an if-statement that checks if ten minutes have
   * passed here, because the sensors, logic and motors all run on the
   * same 10min timer. TODO: Then remove the 10min timers from the 
   * individual functions. */
  Sensors::poll();
  do_logic();
  evaluate_motors();
  check_reset();
}
