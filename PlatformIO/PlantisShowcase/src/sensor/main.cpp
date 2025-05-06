#include <Arduino.h>
#include "SPI.h"
#include "RF24.h"

RF24 radio (20, 17); //CE, CNS

int MOISTURE_SENSOR_PIN = A0;
int MOISTURE_ENABLE_PIN = 0;
int LIGHT_SENSOR_PIN1 = A1;
int LIGHT_SENSOR_ENABLE_PIN = 1;
int RGB_PINS[4][3] = {  //Pins for the RGB leds, sorted {R,G,B}.
  {2,3,4},
  {5,6,7},
  {8,9,10},
  {11,12,13}};

const byte address[6] = "00001"; //Address of receiver

// put function declarations here:
int readMoisture(int enable, int read);
int readLight(int enable, int read);
void radioInit(const byte addr[6]);

void setup() {
  Serial.begin(9600);
  delay(2000);
  //Set up pins
  pinMode(MOISTURE_ENABLE_PIN, OUTPUT);
  digitalWrite(MOISTURE_ENABLE_PIN,LOW);
  pinMode(LIGHT_SENSOR_ENABLE_PIN, OUTPUT);
  digitalWrite(LIGHT_SENSOR_ENABLE_PIN,LOW);
  for (int i = 0; i < 4; i++) { //RGB-LED pins
    for (int j = 0; j < 3; j++) {
        pinMode(RGB_PINS[i][j], OUTPUT);
        digitalWrite(RGB_PINS[i][j],LOW);
    }
  }

  Serial.println("Serial opened");
  //Initializing radio
  radioInit(address);
}

void loop() {
  int moistRead = readMoisture(MOISTURE_ENABLE_PIN,MOISTURE_SENSOR_PIN);
  int lightRead = readLight(LIGHT_SENSOR_ENABLE_PIN,LIGHT_SENSOR_PIN1);

  Serial.println(moistRead,lightRead);
  
  if(moistRead < 500) { //If the moisture level is too low, two of the blue lights glow.
    for(int i = 0; i < 2 ; i++) {
      digitalWrite(RGB_PINS[i][2],HIGH);
    }
    for(int i = 2 ; i < 4 ; i++) {
      digitalWrite(RGB_PINS[i][2],LOW);
    }
  } else { //If it's not too low, all of them glow
    for (int i = 0; i < 4 ; i++){
      digitalWrite(RGB_PINS[i][2],HIGH);
    }
  }

  std::string text = std::to_string(moistRead);
  bool success = radio.write(&text, sizeof(text));
  if (success) {
    Serial.println("Sent successfully");
  } else {
    Serial.println("Failed to send.");
  }

  delay(60000); //1800 sekunder, 30 minutter
}

// put function definitions here:
int readMoisture(int enable, int read) {
  digitalWrite(enable,HIGH);
  delay(10000); //Let the sensor wake up
  int reading = analogRead(read); //Just in case reading clears something up, the first reading tends to be garbage
  reading = analogRead(read);
  digitalWrite(enable,LOW);
  return reading;
}

int readLight(int enable, int read) {
  digitalWrite(LIGHT_SENSOR_ENABLE_PIN,HIGH);
  delay(200); //Let the sensor warm up. I don't know if this is enough
  int reading = analogRead(LIGHT_SENSOR_PIN1);
  digitalWrite(LIGHT_SENSOR_ENABLE_PIN,LOW);
  return reading;
}

void radioInit(const byte addr[6]){
  bool connected = radio.begin(); 
  if (connected) {
    Serial.println("Successfully initialized radio tranceiver.");
  } else {
    Serial.println("Failed to initialize radio tranceiver.");
  }
  radio.openWritingPipe(addr);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}
