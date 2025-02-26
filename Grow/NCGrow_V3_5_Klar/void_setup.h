
void Startup_sekvens() {
    LCD_Startup();          // Start opp LCD-skjermen
    WlcmtoNCGROW();         // Velkomstmelding "Velkommen til Nova Cras GROW"
    delay(3000);            // Vent 3 sekunder
    dsplyMsg();             // Viser meldingen

    setupSensors();         // Aktiverer sensorene (vann og fukt)
    Motor_og_ReleSetup();   // Oppsett av rele og motorer
    setupLys();             // Initialiser lyskontroll
    setupButton();
}

void Motor_kontroll() {
    Motor_setup();          // Sette opp motorene (slå på)
}

