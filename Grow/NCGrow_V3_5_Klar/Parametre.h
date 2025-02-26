// Verdier for vann og fukt (STD verdier før øking til programmer!)
int m_grense = 550;                       // Verdi for fuktgrense (endres via modus fra Innstilling_variabel.h)
const int v_niva_grense = 150;            // Grenseverdi for vann (Konstant verdi)

// Timer data for hvor hyppig programmet skal innhente info
unsigned long tidligereMillis = 0;        // Siste avlesning av sensor
unsigned long interval = 10000;         // Leser av med 20 min intervall (millis konv(20*60*1000)) (endret for pres)
unsigned long aktuellMillis = 0;          // Nåværende tid

// Variabler for sensorverdier
int WaterLevel = 0; 
int Moisture_1 = 0, Moisture_2 = 0, Moisture_3 = 0, Moisture_4 = 0;
int Lys_Nivaa = 0;                        // Endringer her


// Definere motorstatus
bool motor_1_status = false;              // Status for motor nr 1
bool motor_2_status = false;              // Status for motor nr 2
bool motor_3_status = false;              // Status for motor nr 3
bool motor_4_status = false;              // Status for motor nr 4

// Definere lysstatus og tidspunkter
bool lysStatus = false;                   // Status for lyset (på/av)
bool initialSjekk = false;                // Sjekk om lyset er på første gang
unsigned long lysTidStart = 0;            // Tidspunkt for når lyset skrudde seg på/av
const unsigned long lysHoldTid = 20000;   // 30 minutter i millisekunder (Org verdi:1800000, redusert tid for presentasjon til 20000 som er 20 sekunder )
const unsigned long lysDelayTid = 10000; // 15 minutter i millisekunder (Org verdi: 900000, redusert tid for presentasjon til 10000 som er 10 sekunder )

// Legg til lysThreshold
const int lysThreshold = 250;             // Terskelverdi for lysnivå

// Definere Knapp input
int buttonState = 0;                      // Variabel for å lagre statusen til knappen
int lastButtonState = 0;                  // Variabel for å lagre forrige statusen til knappen
unsigned long lastDebounceTime = 0;       // Den siste tiden knappen ble endret
unsigned long debounceDelay = 20;         // Debounce-forsinkelse (millisekunder)
int currentValue = 550;                   // Startverdi

