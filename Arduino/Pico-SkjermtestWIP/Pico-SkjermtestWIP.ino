#include "SPI.h"
#include "TFT_eSPI.h"


int MkShft_VCC = 14;
int RESET_PIN = 15;
int DATA_COMMAND_PIN = 13;
int BACKLIGHT_PIN = A0;
int CHIP_SELECT_PIN = 17;

TFT myScreen = TFT(CHIP_SELECT_PIN, DATA_COMMAND_PIN, RESET_PIN);

void setup() {
  // put your setup code here, to run once:
  pinMode(MkShft_VCC, OUTPUT);

  digitalWrite(MkShft_VCC,HIGH);
  analogWrite(BACKLIGHT_PIN,500);

  myScreen.begin();
  myScreen.background(0,0,0);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  myScreen.stroke(255,0,0);
  myScreen.line(0,10,myScreen.width(),10);
  delay(1000);
  myscreen.background(0,0,0);
  delay(1000);
  myScreen.background(150,150,150);
  delay(1000);
  myScreen.bacground(0,0,0);
  delay(1000);
}
