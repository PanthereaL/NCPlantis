#include <SPI.h>
#include <SD.h>

File logFile;

//Pin definitions
int SENSOR_PIN[] = { A0, A1 };

int sensorReading[2];
unsigned long myIndex = 0;

void setup() {
  Serial.begin(9600);
  if (!Serial) {
    delay(500); //Waits half a second for Serial to get set up.
  }

  Serial.println("Initializing SD card...");
  if (!SD.begin(SS)) {
    Serial.println("Failed to initialize SD card");
    while (1)
      ;
  } else {
    Serial.println("Successfully initialized card");
  }

  logFile = SD.open("fuktlog.txt", FILE_WRITE);
  logFile.println("index,sensor1,sensor2");
  logFile.close();
  delay(1000);  //Waits for a second jsut to amke sure everything is powered.
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 2; i++) {
    sensorReading[i] = analogRead(SENSOR_PIN[i]);
  }

  logFile = SD.open("fuktlog.txt", FILE_WRITE);
  logFile.println(
    String(myIndex) + "," + String(sensorReading[0]) + "," + String(sensorReading[1]));

  Serial.println(
    String(myIndex) + "," + String(sensorReading[0]) + "," + String(sensorReading[1]));
  logFile.close();
  myIndex++;
  delay(1800000);  //wait for half an hour.
}
