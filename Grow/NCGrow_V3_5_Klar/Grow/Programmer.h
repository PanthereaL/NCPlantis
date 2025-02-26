// Justerbare innstillinger via knapper på Breadboard. (Framtidig justering over til RFID istedefor knapper)
/*
enum Modus {NORMAL, HIGH};        // Definerer de ulike modusene
Modus aktuellModus = NORMAL;      // Setter standard modus til NORMAL

const int normalFuktGrense = 550; // Fuktighetsgrense for NORMAL modus
const int highFuktGrense = 400;   // Fuktighetsgrense for HIGH modus

int gjeldendeFuktGrense = normalFuktGrense; // Start med normal fuktighetsgrense

void setupProgrammer() {
  pinMode(knappPin, INPUT_PULLUP); // Sett knappPin som input med pullup
}

void oppdaterModus() {
  knappStatus = digitalRead(knappPin) == LOW; // Leser knappens status (aktiv lav)

  if (knappStatus) {
    delay(200);                  // Debouncing
    while (digitalRead(knappPin) == LOW); // Vent til knappen slippes
    delay(200);                  // Debouncing

    // Bytter modus
    if (aktuellModus == NORMAL) {
      aktuellModus = HIGH;
      gjeldendeFuktGrense = highFuktGrense;
      Serial.println("Modus: HIGH");
    } else {
      aktuellModus = NORMAL;
      gjeldendeFuktGrense = normalFuktGrense;
      Serial.println("Modus: NORMAL");
    }
  }
}






