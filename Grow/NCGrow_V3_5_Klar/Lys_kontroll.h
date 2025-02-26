void setupLys() {
    pinMode(relePin, OUTPUT);             // Sett lysrele som output
    digitalWrite(relePin, HIGH);          // Sørg for at lyset er av ved oppstart (invertert logikk)
}

void oppdaterLys() {
    unsigned long aktuellTid = millis();  // Nåværende tid i millisekunder

    if (!initialSjekk) {
        if (Lys_Nivaa < lysThreshold) {
            skruPaaLys(aktuellTid);
            return;                       // Gå ut av funksjonen for å unngå å gå inn i forsinkelseslogikken umiddelbart
        }
    }

    if (lysStatus) {                                  // Hvis lyset er på
        if (aktuellTid - lysTidStart >= lysHoldTid) { // Hvis 30 minutter har gått
            skruAvLys(aktuellTid);
        }
    } else {
        if (aktuellTid - lysTidStart >= lysDelayTid) { // Hvis forsinkelsen er over
            if (Lys_Nivaa < lysThreshold) {            // Hvis lysnivået er under terskelen
                skruPaaLys(aktuellTid);
            }
        }
    }

    // Feilsøkingsutskrift for lysstatus og lysnivå
    printLysStatus(Lys_Nivaa, lysStatus);
}

// Funksjon for å skru på lyset
void skruPaaLys(unsigned long tid) {
    digitalWrite(relePin, LOW);        // Skru på lyset (invertert logikk)
    lysStatus = true;
    lysTidStart = tid;
}

// Funksjon for å skru av lyset
void skruAvLys(unsigned long tid) {
    digitalWrite(relePin, HIGH);       // Skru av lyset (invertert logikk)
    lysStatus = false;
    lysTidStart = tid;
}
