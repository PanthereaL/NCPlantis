#include <SPI.h>
#include <SD.h>

File logFile;

//Pin definitions
int SENSOR_PIN[] = { A0 };
int SENSOR_EN_PIN[] = { 1 };
int BUZZER_PIN = 3;

int sensorReading[1];
unsigned long myIndex = 0;
unsigned long startTime = 0;
unsigned long nextRun = 0;
int numberOfRuns = 0;

void setup() {
  Serial.begin(9600);
  if (!Serial) {
    delay(1000);  //Waits a second for Serial to get set up.
  }

  Serial.println("Initializing SD card...");
  if (!SD.begin(SS)) {
    Serial.println("Failed to initialize SD card");
    while (1)
      ;
  } else {
    Serial.println("Successfully initialized card");
  }

  pinMode(SENSOR_EN_PIN[0], OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  logFile = SD.open("fuktlog.txt", FILE_WRITE);
  logFile.println("Test Powered up, starting");
  logFile.close();
  delay(1000);  //Waits for a second just to make sure everything is powered.

  startTime = millis();
  nextRun = startTime + 1200000;  //3,600,000 is one hour in ms
}

void loop() {
  numberOfRuns++;
  //Write main header
  logFile = SD.open("fuktlog.txt", FILE_WRITE);
  logFile.println("Main run no. " + String(numberOfRuns));
  logFile.flush();
  //Start sub runs
  //Run 1, only the first sensor
  logFile.println("Sub-run 1");
  logFile.close();
  digitalWrite(SENSOR_EN_PIN[0], HIGH);
  myIndex = 0;
  delay(20000);  //wait for ten second to power up the sensor
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 1; j++) {
      sensorReading[j] = analogRead(SENSOR_PIN[j]);
    }

    logFile = SD.open("fuktlog.txt", FILE_WRITE);
    logFile.println(
      String(myIndex) + "," + String(sensorReading[0]));

    Serial.println(
      String(myIndex) + "," + String(sensorReading[0]));
    logFile.close();
    myIndex++;
    delay(5000);  //Waits 5 sek, should be accurate enough
  }
  digitalWrite(SENSOR_EN_PIN[0], LOW);
  //Do a beep, now we're done!
  tone(BUZZER_PIN, 500, 200);
  delay(350);
  tone(BUZZER_PIN, 500, 200);
  delay(350);
  tone(BUZZER_PIN, 500, 200);
  //wait for next run
  while (millis() < nextRun) { ; }
  nextRun = nextRun + 1200000;
}
