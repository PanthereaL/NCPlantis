
void setupSensors() {
    pinMode(msensorpin1, INPUT); // Satt som input for fuktsensor 1
    pinMode(msensorpin2, INPUT); // Satt som input for fuktsensor 2
    pinMode(msensorpin3, INPUT); // Satt som input for fuktsensor 3
    pinMode(msensorpin4, INPUT); // Satt som input for fuktsensor 4
    pinMode(wsensorpin, INPUT);  // Satt som input for vannivå sensor
    pinMode(lsensorpin, INPUT);  // Satt som input for lysnivå sensor (LDR)
}

void SensorFunctions() {
    // Les av sensorverdier
    WaterLevel = analogRead(wsensorpin);  // Les av vannnivå
    Moisture_1 = analogRead(msensorpin1); // Les av fuktsensor 1
    Moisture_2 = analogRead(msensorpin2); // Les av fuktsensor 2
    Moisture_3 = analogRead(msensorpin3); // Les av fuktsensor 3
    Moisture_4 = analogRead(msensorpin4); // Les av fuktsensor 4
    Lys_Nivaa = analogRead(lsensorpin);   // Les av lysnivå (LDR)

    // Send verdier til Serial Monitor for kalibrering og overvåking
    printSensorValues(WaterLevel, Moisture_1, Moisture_2, Moisture_3, Moisture_4, m_grense, Lys_Nivaa, lysStatus);
}
