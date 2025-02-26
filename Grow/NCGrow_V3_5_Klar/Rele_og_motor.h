
// Funksjonserklæringer
void skruPaaMotor(int motorPin);
void skruAvMotor(int motorPin);
void skruAvMotorer();
void settMotorStatus(int motorPin, bool status);

// Oppsett av motorer og rele
void Motor_og_ReleSetup() {
    pinMode(M_1, OUTPUT); // Satt som output for motor 1
    pinMode(M_2, OUTPUT); // Satt som output for motor 2
    pinMode(M_3, OUTPUT); // Satt som output for motor 3
    pinMode(M_4, OUTPUT); // Satt som output for motor 4

    skruAvMotorer(); // Initialiser motorer som av (LOW)
}

// Funksjon for å slå på alle motorer
void Motor_setup() {
    skruPaaMotor(M_1); // Slå på motor 1
    skruPaaMotor(M_2); // Slå på motor 2
    skruPaaMotor(M_3); // Slå på motor 3
    skruPaaMotor(M_4); // Slå på motor 4
}

// Funksjon for å slå av/på motorer basert på fuktighet
void Motor_Off_ON(bool verdi1, bool verdi2, bool verdi3, bool verdi4) {
    motor_1_status = verdi1; // Oppdater status for motor 1
    motor_2_status = verdi2; // Oppdater status for motor 2
    motor_3_status = verdi3; // Oppdater status for motor 3
    motor_4_status = verdi4; // Oppdater status for motor 4

    settMotorStatus(M_1, motor_1_status); // Sett status for motor 1
    settMotorStatus(M_2, motor_2_status); // Sett status for motor 2
    settMotorStatus(M_3, motor_3_status); // Sett status for motor 3
    settMotorStatus(M_4, motor_4_status); // Sett status for motor 4

    // Feilsøkingsutskrift for å verifisere motorstatus
    //printMotorStatus(motor_1_status, motor_2_status, motor_3_status, motor_4_status);
}

// Funksjon for å sjekke om noen motorer er på
bool sjekker_motor_tilstand() { 
    return (digitalRead(M_1) == HIGH) || (digitalRead(M_2) == HIGH) || 
           (digitalRead(M_3) == HIGH) || (digitalRead(M_4) == HIGH);  // Returnerer true hvis noen motorer er PÅ
}

// Funksjon for å sjekke status for en bestemt motor
bool sjekkMotor(int motorPin) {
    return digitalRead(motorPin) == HIGH;                             // Returnerer true hvis motoren er PÅ
}

// Implementering av funksjoner for å slå på/av en motor
void skruPaaMotor(int motorPin) {
    digitalWrite(motorPin, HIGH); // Slå på motoren (HIGH)
}

void skruAvMotor(int motorPin) {
    digitalWrite(motorPin, LOW); // Slå av motoren (LOW)
}

// Funksjon for å slå av alle motorer
void skruAvMotorer() {
    skruAvMotor(M_1); // Slå av motor 1
    skruAvMotor(M_2); // Slå av motor 2
    skruAvMotor(M_3); // Slå av motor 3
    skruAvMotor(M_4); // Slå av motor 4
}

// Funksjon for å sette motorstatus
void settMotorStatus(int motorPin, bool status) {
    digitalWrite(motorPin, status ? HIGH : LOW);
    Serial.print("Motor ");
    Serial.print(motorPin - 1); // Justere for å vise motor nummer korrekt
    Serial.println(status ? " på" : " av");
}
