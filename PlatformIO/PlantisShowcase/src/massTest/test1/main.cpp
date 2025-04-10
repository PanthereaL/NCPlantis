/* 
 * This is supposed to be the simple code for the long term moisture tests
 * for the project. It will have two MCUs reading from five sensors, same as 
 * the simple tests from before.
 */

#include <Arduino.h>
#include "SPI.h"
#include "SD.h"
//#include "Beeper.h" TODO
//#include "Sensors.h" TODO

//Variable declarations
File logFile;
const int numOfSensors = 5;
int sensorRead[numOfSensors];
unsigned long nextRead;
int currentIndex = 0;

//Pin definition
int SENSOR_PIN[] = {A0, A1};
int SELECT_PIN[] = {1, 2};
int BUZZER_PIN = 3;

void setup() {
    Serial.begin(9600);

    //initialize three sensors. These come from a class "Sensors.h" TODO

    //Deal with pin modes
    pinMode(BUZZER_PIN,OUTPUT);
    pinMode(SELECT_PIN[0],OUTPUT);
    pinMode(SELECT_PIN[1],OUTPUT);

    if(!Serial) {
        delay(1500); //Wait a second and a half just to make sure Serial is ready.
    }

    //initialize SD card
    Serial.println("Initializing SD card...");
    if (!SD.begin(SS)) {
        Serial.println("Failed to initialize SD card.");
        Serial.println("Check connection and try again.");
        //play an error beep TODO
        while (1) {}
    } else {
        Serial.println("Successfully initialized SD card.");
    }

    //setup SD card with header
    logFile = SD.open("fuktlog.txt", FILE_WRITE);
    logFile.println("index,Sensor1,Sensor2,Sensor3,Sensor4,Sensor5");
    logFile.close();

    //play startup beep TODO

    while (millis() < 5000) {} //Just waits until the system has been on for 5 seconds
    nextRead = millis() + 300000; //Now + 5 min.
}

void loop() {
    currentIndex++;
    //read from sensors
    for (int i = 0 ; i < numOfSensors ; i++) {
        digitalWrite(SELECT_PIN[0], (i & 0b100) >> 2);
        digitalWrite(SELECT_PIN[1], (i & 0b010) >> 1);
        sensorRead[i] = analogRead(SENSOR_PIN[i%2]);
    }
    //write to SD card
    String tmp_output = String(currentIndex);
    for (int i = 0 ; i < numOfSensors ; i++) {
        tmp_output += ("," + sensorRead[i]);
    }

    logFile = SD.open("fuktlog.txt", FILE_WRITE);
    logFile.println(tmp_output);
    logFile.close();

    //play action complete beep TODO

    //wait until next time
    while (millis() < nextRead);
    nextRead = nextRead + 300000;
}