//#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27, 16, 2);

int SENSOR_PIN[] = { A0, A1, A2 };

void setup() {
  // put your setup code here, to run once:
  //pinMode(BUTTON_PIN, INPUT_PULLDOWN);
  //lcd.init();
  //lcd.backlight();
  //delay(650);
  //lcd.clear();
  Serial.begin(9600);
  if (!Serial) {
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorRead[3];
  for (int i = 0; i < 3; i++) {
    sensorRead[i] = analogRead(SENSOR_PIN[i]);
  }
  Serial.println("Sensor1: " + String(sensorRead[0]) + ", Sensor2: " + String(sensorRead[1]) + ", Sensor3: " + String(sensorRead[2]));
  delay(750);
}
