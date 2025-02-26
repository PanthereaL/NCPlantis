
// Funksjoner for lyskontroll
void setupLys();
void oppdaterLys();
void skruPaaLys(unsigned long tid);
void skruAvLys(unsigned long tid);

// Funksjoner for motor- og relekontroll
void skruPaaMotor(int motorPin);
void skruAvMotor(int motorPin);
void skruAvMotorer();
void settMotorStatus(int motorPin, bool status);
void Motor_og_ReleSetup();
void Motor_setup();
void Motor_Off_ON(bool verdi1, bool verdi2, bool verdi3, bool verdi4);
bool sjekker_motor_tilstand();
bool sjekkMotor(int motorPin);

// Funksjoner for sensorer
void setupSensors();
void SensorFunctions();

// Funksjoner for oppsett og loop
void Startup_sekvens();
void Motor_kontroll();
void loop_sensor_funksjoner();
void sjekk();
void loop_motor_Off_ON();

// Funksjoner for Serial Monitor
void printSensorValues(int waterLevel, int moisture1, int moisture2, int moisture3, int moisture4, int m_grense, int lysNivaa, bool lysStatus);
void printLysStatus(int lysNivaa, bool lysStatus);
void printMotorStatus(bool motor1, bool motor2, bool motor3, bool motor4);

// Funksjon for å initialisere knappen
void setupButton();

// Funksjon for å håndtere knappepress
void handleButtonPress();
