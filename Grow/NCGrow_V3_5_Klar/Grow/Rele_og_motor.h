const int
M_1 = 2, // Motor nr 1 (PIN)
M_2 = 3, // Motor nr 2 (PIN)
M_3 = 4, // Motor nr 3 (PIN)
M_4 = 5; // Motor nr 4 (PIN)

bool motor_1_status = false; // Status for motor nr 1
bool motor_2_status = false; // Status for motor nr 2
bool motor_3_status = false; // Status for motor nr 3
bool motor_4_status = false; // Status for motor nr 4

void Motor_og_ReleSetup() {

  pinMode(M_1, OUTPUT);       // Definert som output!
  pinMode(M_2, OUTPUT);       //      ----"----
  pinMode(M_3, OUTPUT);       //          "
  pinMode(M_4, OUTPUT);       //          "

  digitalWrite(M_1, LOW);     // AV
  digitalWrite(M_2, LOW);     // AV
  digitalWrite(M_3, LOW);     // AV
  digitalWrite(M_4, LOW);     // AV
}

void Motor_setup() {

  digitalWrite(M_1, HIGH);    // PÅ
  digitalWrite(M_2, HIGH);    // PÅ
  digitalWrite(M_3, HIGH);    // PÅ
  digitalWrite(M_4, HIGH);    // PÅ

}

void Motor_Off_ON(bool verdi1, bool verdi2, bool verdi3, bool verdi4) { // Funksjon for å slå motorer AV/PÅ basert på fuktighet

  motor_1_status = verdi1; // Oppdaterer status for motor 1
  motor_2_status = verdi2; // Oppdaterer status for motor 2
  motor_3_status = verdi3; // Oppdaterer status for motor 3
  motor_4_status = verdi4; // Oppdaterer status for motor 4

  digitalWrite(M_1, motor_1_status ? HIGH : LOW); // Sette motor 1 (LOW = AV, HIGH = PÅ)
  digitalWrite(M_2, motor_2_status ? HIGH : LOW); // Sette motor 2 (LOW = AV, HIGH = PÅ)
  digitalWrite(M_3, motor_3_status ? HIGH : LOW); // Sette motor 3 (LOW = AV, HIGH = PÅ)
  digitalWrite(M_4, motor_4_status ? HIGH : LOW); // Sette motor 4 (LOW = AV, HIGH = PÅ)

  // Feilsøkingsutskrift for å verifisere motorstatus
  Serial.print("Motor 1 status: "); 
  Serial.println(digitalRead(M_1) == LOW ? "O" : "I"); // Sjekker om motor 1 er AV/PÅ
  Serial.print("Motor 2 status: "); 
  Serial.println(digitalRead(M_2) == LOW ? "O" : "I"); // Sjekker om motor 2 er AV/PÅ
  Serial.print("Motor 3 status: "); 
  Serial.println(digitalRead(M_3) == LOW ? "O" : "I"); // Sjekker om motor 3 er AV/PÅ
  Serial.print("Motor 4 status: "); 
  Serial.println(digitalRead(M_4) == LOW ? "O" : "I"); // Sjekker om motor 4 er AV/PÅ
}

// Funksjon for å sjekke om noen motorer er på
bool sjekker_motor_tilstand() { 
  return (digitalRead(M_1) == HIGH) || (digitalRead(M_2) == HIGH) || 
         (digitalRead(M_3) == HIGH) || (digitalRead(M_4) == HIGH); // Returnerer true hvis noen motorer er PÅ
}

// Funksjon for å sjekke status for en bestemt motor
bool sjekkMotor(int motorPin) {
  return digitalRead(motorPin) == HIGH; // Returnerer true hvis motoren er PÅ
}

