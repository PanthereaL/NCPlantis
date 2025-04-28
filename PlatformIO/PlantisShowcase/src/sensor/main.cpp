#include <Arduino.h>
#include "SPI.h"
#include "RF24.h"

RF24 radio (7, 8);

int MOISTURE_SENSOR_PIN = A0;
int LIGHT_SENSOR_PIN1 = A1;
const byte address[5] = {'0', '0', '0', '0', '1'};
const byte test[6] = "00002";
// put function declarations here:

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
}

void loop() {
  const char text[] = "Hello RF!";
  bool success = radio.write(&text, sizeof(text));
  if (success) {
    Serial.println("Sent successfully");
  } else {
    Serial.println("Failed to send.");
  }
}

// put function definitions here: