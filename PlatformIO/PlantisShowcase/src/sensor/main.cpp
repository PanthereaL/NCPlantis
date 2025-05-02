#include <Arduino.h>
#include "SPI.h"
#include "RF24.h"

RF24 radio (20, 21); //CE, CNS

int MOISTURE_SENSOR_PIN = A0;
int LIGHT_SENSOR_PIN1 = A1;
const byte address[5] = {'0', '0', '0', '0', '1'};
// put function declarations here:

void setup() {
  Serial.begin(9600);
  delay(2000);
  Serial.println("Serial opened");
  bool connected = radio.begin(); 
  if (connected) {
    Serial.println("Successfully initialized radio tranceiver.");
  } else {
    Serial.println("Failed to initialize radio tranceiver.");
  }
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {
  int measurement = analogRead(MOISTURE_SENSOR_PIN);
  std::string text = std::to_string(measurement);
  bool success = radio.write(&text, sizeof(text));
  if (success) {
    Serial.println("Sent successfully");
  } else {
    Serial.println("Failed to send.");
  }
  delay(120000); //two minutes in ms
}

// put function definitions here: