
void setupButton() {
    pinMode(buttonPin, INPUT_PULLUP);  // Bruk intern pull-up motstand
    lastButtonState = digitalRead(buttonPin);  // Les første statusen til knappen
    Serial.println(currentValue);      // Skriv ut startverdi
}

void handleButtonPress() {
    int reading = digitalRead(buttonPin);  // Les statusen til knappen

    // Oppdage et trykk når knappen går fra høy til lav umiddelbart
    if (reading == LOW && buttonState == HIGH) {
        // Bytt verdien av m_grense
        if (m_grense == 550) {
            m_grense = 300;
        } else {
            m_grense = 550;
        }
        Serial.println(m_grense);  // Skriv ut den nye verdien
    }

    // Oppdater knappens tilstand
    buttonState = reading;  
}

