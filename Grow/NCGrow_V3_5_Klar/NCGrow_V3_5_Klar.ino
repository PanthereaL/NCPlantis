#include "Include.h"

void setup() {
    Serial.begin(9600);
    Startup_sekvens();
    setupReset();               // Initialiserer reset-timingen
    Motor_kontroll();
}

void loop() {
    unsigned long aktuellMillis = millis();
    sjekk();                    // Sjekk av motorstatus og oppdater intervall
    
    loop_sensor_funksjoner();   // Gruppering av sensorfunksjoner
    loop_motor_Off_ON();        // Slå av/på motorer basert på fuktighet
    oppdaterLys();              // Oppdater lysstatus
    handleButtonPress();        // Håndter knappepress
    checkReset();               // Sjekk om vi trenger å resette

    delay(1000);                // Vent 1 sekund før ny loop
}
