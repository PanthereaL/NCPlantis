#include <SD.h>
#include <SPI.h>

File logFile;

//Pin definitions
int SENSOR_PIN[] = {26, 27, 28, 29};
int BUTTON_PIN[] = {9, 10, 11};

int num = 0; //For the loops

int sensorReading[4];
int buttonState[3];

void setup() {
  Serial.begin(9600); //Not necessary, but nice for debug
  while (!Serial) {
    ; //Make sure Serial is connected before moving on
  }

  //Setting up the button pins
  for (int i = 0 ; i < 3 ; i++) {
    pinMode(BUTTON_PIN[i], INPUT);
  }

  //Initializing the SD card
  Serial.println("Initializing SD card...");
  if(!SD.begin(SS,SPI1)) {
    Serial.println("Failed to initialize SD card");
    while (1);
  } else {
    Serial.println("Successfully initialized card");
  }
}

void loop() {
  //If we're currently testing:
  if(num){
    logFile = SD.open("log.txt", FILE_WRITE);
    if (!logFile) {
      Serial.println("Failed to open log.txt");
    }

    if (num > 1) {
      delay(60000); //Wait a minute if we're measuring the long runs.
    }

    logFile.println("index,sensor1,sensor2,sensor3,sensor4");
    for(int i = 1 ; i <= num ; i++) {
      for(int j = 0 ; i < 4 ; j++) {
        sensorReading[j] = analogRead(SENSOR_PIN[j]);
      }
      logFile.println(
        String(i)+","+
        String(sensorReading[0])+","+
        String(sensorReading[1])+","+
        String(sensorReading[2])+","+
        String(sensorReading[3])
        );
      delay(1000); //Wait for one second. A little impresise.
    }
    logFile.close();
    num = 0;
  }

  //Polling the buttons
  for (int i = 0 ; i < 3 ; i++) {
    buttonState[i] = digitalRead(BUTTON_PIN[i]);
  }

  //Setting the correct value of num
  if (buttonState[0]) {
    num = 1;
  } else if (buttonState[1]) {
    num = 60;
  } else if (buttonState[2]) {
    num = 900;
  }
}
