
// Funksjon for å printe sensorverdier til Serial Monitor
void printSensorValues(int waterLevel, int moisture1, int moisture2, int moisture3, int moisture4, int m_grense, int lysNivaa, bool lysStatus) {
    Serial.print("Vannnivå: ");
    Serial.print(waterLevel);                              // Print vannivå
    Serial.print(" | Fuktnivå 1: ");
    Serial.print(moisture1);                               // Print fuktnivå 1
    Serial.print(" | Fuktnivå 2: ");
    Serial.print(moisture2);                               // Print fuktnivå 2
    Serial.print(" | Fuktnivå 3: ");
    Serial.print(moisture3);                               // Print fuktnivå 3
    Serial.print(" | Fuktnivå 4: ");
    Serial.print(moisture4);                               // Print fuktnivå 4
    Serial.print(" | P: ");
    Serial.print(m_grense);                                // Print m_grense
    Serial.print(" | Lysnivå: ");
    Serial.print(lysNivaa);                                // Print lysnivå
    Serial.print(" | Lys status: ");
    Serial.println(lysStatus ? "I" : "O");                 // Print lysstatus (I/O)
}

// Funksjon for å printe motorstatus til Serial Monitor
void printMotorStatus(bool motor1, bool motor2, bool motor3, bool motor4) {
    Serial.print("Motor 1 status: ");
    Serial.println(motor1 ? "PÅ" : "AV");                  // Print status for motor 1
    Serial.print("Motor 2 status: ");
    Serial.println(motor2 ? "PÅ" : "AV");                  // Print status for motor 2
    Serial.print("Motor 3 status: ");
    Serial.println(motor3 ? "PÅ" : "AV");                  // Print status for motor 3
    Serial.print("Motor 4 status: ");
    Serial.println(motor4 ? "PÅ" : "AV");                  // Print status for motor 4
}

// Funksjon for å printe lysstatus til Serial Monitor
void printLysStatus(int lysNivaa, bool lysStatus) {
    Serial.print("Lysnivå: ");
    Serial.print(lysNivaa);                                // Print lysnivå
    Serial.print(" | Lys status: ");
    Serial.println(lysStatus ? "I" : "O");                 // Print lysstatus (I/O)
}
