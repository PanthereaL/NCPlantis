
void loop_sensor_funksjoner() {
    SensorFunctions(); // Oppdaterer sensorverdier og skriver til Serial Monitor
    updateDisplay(Lys_Nivaa, WaterLevel, sjekkMotor(M_1), sjekkMotor(M_2), sjekkMotor(M_3), sjekkMotor(M_4)); // Oppdaterer LCD-skjermen med sensor- og motorstatus
}

void sjekk() {
    if (sjekker_motor_tilstand()) {
        interval = 1000;                 // Sjekk motorstatus hvert sekund når motorene er på
    } else {
        interval = 10000;              // Sjekk motorstatus hvert 20. minutt når motorene er av (Org: 1200000, 10k for pres)
    }
    
    // Sjekk om det er tid for neste avlesning
    if (aktuellMillis - tidligereMillis >= interval) {
        tidligereMillis = aktuellMillis; // Oppdater siste avlesningstid
        loop_sensor_funksjoner();        // Oppdater sensorfunksjoner
    }
}

void loop_motor_Off_ON() {
    Motor_Off_ON(
        Moisture_1 < m_grense,
        Moisture_2 < m_grense,
        Moisture_3 < m_grense,
        Moisture_4 < m_grense
    );
    delay(1000);                         // Vent 1 sekund før ny loop
}


