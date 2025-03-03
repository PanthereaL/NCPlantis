#include "Arduino.h"
#include "display_config.h"

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
//I'm not sure if this works when it's just here.

//External Variables
const unsigned long displayDelay = 20000; //20 seconds

//Internal variables

//Functions
void initiate_display() {
  lcd.init();
  delay(650);
  lcd.clear();
}

void update_display(const String& line1, const String& line2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

void welcome_to_grow() {
  update_display("Velkommen til", "Nova Cras Grow");
}

namespace Display {
void turn_on() {
  lcd.display();
  lcd.backlight();
}
void turn_off() {
  lcd.clear();
  lcd.noDisplay();
  lcd.noBacklight();
}
}
