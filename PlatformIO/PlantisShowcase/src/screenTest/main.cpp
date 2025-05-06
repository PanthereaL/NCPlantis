#include <Arduino.h>
//#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#define TFT_DC 16
#define TFT_CS 22
//#define TFT_MOSI 10
//#define TFT_CLK 8
#define TFT_RST 23
#define TFT_BLK 21

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

//TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

void drawPattern();

void setup(void) {
  Serial.begin(9600);
  pinMode(TFT_BLK, OUTPUT);
  digitalWrite(TFT_BLK,HIGH);
  
  tft.init(240, 320, SPI_MODE2);
  tft.invertDisplay(true);
  tft.fillScreen(ST77XX_BLACK);

}
void loop() {
}

void drawPattern() {
  int centerX = tft.width() /2;
  int centerY = tft.height() /2;

  for (int radius = 10; radius <= 120; radius += 10) {
    uint16_t color = (radius/10) % 2 == 0 ? ST77XX_BLUE : ST77XX_CYAN;
    tft.drawCircle(centerX, centerY, radius, color);
  }

  for (int angle = 0; angle < 360; angle += 15) {
    float radians = angle * 3.14159 /180;
    int x1 = centerX;
    int y1 = centerY;
    int x2 = centerX + 120 * cos(radians);
    int y2 = centerY + 120 * sin(radians);
    uint16_t color = (angle/15) % 2 == 0 ? ST77XX_RED : ST77XX_YELLOW;
    tft.drawLine(x1, y1, x2, y2, color);
  }
  
  tft.fillCircle(centerX, centerY, 10, ST77XX_GREEN);
}