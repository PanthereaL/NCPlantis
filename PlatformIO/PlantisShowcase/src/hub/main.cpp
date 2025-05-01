#include <Arduino.h>
#include "SPI.h"
#include "RF24.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#define TFT_CS 13
#define TFT_RST 11
#define TFT_DC 10

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

RF24 radio (20, 21); //CE, CNS

int MOISTURE_SENSOR_PIN = A0;
int LIGHT_SENSOR_PIN1 = A1;
const byte address[5] = {'0', '0', '0', '0', '1'};
const byte test[6] = "00002";
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
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();

  tft.init(240, 320, SPI_MODE1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(20, 40);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.print("Hello, Pico!");
}

void loop() {
  
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}

// put function definitions here: