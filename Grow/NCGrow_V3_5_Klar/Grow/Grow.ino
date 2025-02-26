#include "Include.h"


void setup() {

  Serial.begin(9600);
  Startup_sekvens();
  Motor_kontroll();

}

void loop() {

  unsigned long aktuellMillis = millis();

  sjekk();                                // Sjekk av motor status, og oppdatere intervallet
  loop_sensor_funksjoner();               //Gruppering av Sensor funksjoner
  loop_motor_Off_ON();
  oppdaterLys();                          // Oppdater lysstatus
  oppdaterModus();                        // Oppdaterer modus etter input

  delay(1000);                            // Vente 1 sekund før ny loop

}