/* Denne funksjonen sikrer at Arduino-enheten tilbakestilles automatisk hver 24. time (kl 00:00). 
   Dette bidrar til å forhindre potensielle minnelekkasjer, opprettholder stabiliteten i systemet 
   og løser eventuelle feil som kan ha oppstått i løpet av dagen. Ved å ha en daglig tilbakestilling 
   sikrer vi at systemet starter med en "ren" tilstand, noe som forbedrer den langsiktige ytelsen og påliteligheten.*/

unsigned long startMillis;
const unsigned long resetInterval = 86400000; // 24 timer i millisekunder



void setupReset() {
    startMillis = millis(); // Lagrer starttiden
}

// Funksjon for å reset Arduinoen
void resetArduino() {
    asm volatile ("  jmp 0"); // Bruker en assembler-instruksjon for å hoppe til startadressen
}

void checkReset() {
    unsigned long currentMillis = millis(); // Henter gjeldende tid

    // Sjekk om reset-intervallet har gått
    if (currentMillis - startMillis >= resetInterval) {
        resetArduino();
    }
}

