#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#include "Plant.h"

#define TFT_CS 16
#define TFT_RST 23
#define TFT_DC 22

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
RF24 radio (0, 17); //CE, CNS

Plant myPlant("Monstera", LightLevel::MEDIUM, MoistureLevel::MEDIUM);

const byte address[5] = {'0', '0', '0', '0', '1'};

const uint16_t lineSpace = 20; //Pixels between each line, assuming text size 2.


// put function declarations here:
void printToScreen(
  const char* tekst, 
  uint16_t x = 20, 
  uint16_t y = 40, 
  uint16_t textSize = 2, 
  uint16_t textColor = ST77XX_BLACK
);

void screenClear(uint16_t color = ST77XX_WHITE);

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

  tft.init(240, 320, SPI_MODE2);
  tft.invertDisplay(false);
  screenClear();
  printToScreen("Hello, ESP!");
}

void loop() {
  
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    screenClear();
    printToScreen(text);
  }
  screenClear();
  printToScreen("Overskrift", 10, 10, 3);
  printToScreen("TEst", 20, 2*lineSpace);
  printToScreen("Debug",20, 3*lineSpace);
  delay(1000);
}

// put function definitions here:

void printToScreen(
  const char *text, 
  uint16_t x = 20, 
  uint16_t y = 40, 
  uint16_t textSize = 1, 
  uint16_t textColor = ST77XX_WHITE
)
{
  tft.setCursor(x,y);
  tft.setTextColor(textColor);
  tft.setTextSize(textSize);
  tft.print(text);
}

void screenClear(uint16_t color)
{
  tft.fillScreen(color);
}
