const int relePin = 7;              // Pin for lys rele
const int lysThreshold = 1000;      // Verdi for å skru på lyset

bool lysStatus = false;             // Status for lyset (på/av)
bool initialSjekk = false;          // Sjekk om lyset er på første gang
unsigned long lysTidStart = 0;      // Tidspunkt for når lyset skrudde seg på/av
const unsigned long lysHoldTid = 1800000; // 30 minutter i millisekunder
const unsigned long lysDelayTid = 900000; // 15 minutter i millisekunder

void setupLys() {
  pinMode(relePin, OUTPUT);         // Sett lys rele som output
  digitalWrite(relePin, HIGH);      // Sørger for at lyset er av ved oppstart (invertert logikk)
}

void oppdaterLys() {
  unsigned long aktuellTid = millis(); // Nåværende tid i millisekunder
  int lysNivaa = Lys_Nivaa;           // Bruker lysnivå fra Inputs.h

  if (!initialSjekk) {
    if (lysNivaa < lysThreshold) {
      digitalWrite(relePin, LOW);     // Skru på lyset (invertert logikk)
      lysStatus = true;               // Oppdater lys status
      initialSjekk = true;            // Merk at initial sjekk er utført
      lysTidStart = aktuellTid;       // Oppdater starttid for lyset
      return;                         // Går ut av funksjonen for å unngå å gå inn i forsinkelseslogikken umiddelbart
    }
  }

  if (lysStatus) {                    // Hvis lyset er på
    if (aktuellTid - lysTidStart >= lysHoldTid) { // Hvis 30 minutter har gått
      digitalWrite(relePin, HIGH);    // Skru av lyset (invertert logikk)
      lysStatus = false;              // Oppdater lys status
      lysTidStart = aktuellTid;       // Oppdater starttid for forsinkelse
    }
  } else {
    if (aktuellTid - lysTidStart >= lysDelayTid) { // Hvis forsinkelsen er over
      if (lysNivaa < lysThreshold) {  // Hvis lysnivået er under terskelen
        digitalWrite(relePin, LOW);   // Skru på lyset (invertert logikk)
        lysStatus = true;             // Oppdater lys status
        lysTidStart = aktuellTid;     // Oppdater starttid for lyset
      }
    }
  }

  // Feilsøkingsutskrift for lysstatus og lysnivå
  Serial.print("Lysnivå: ");
  Serial.print(lysNivaa);
  Serial.print(" | Lys status: ");
  Serial.println(lysStatus ? "PÅ" : "AV");
}
 



