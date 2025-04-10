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

//Pin definition
int SENSOR_PIN[] = {};
int BUZZER_PIN = 3;

void setup() {
    Serial.begin(9600);

    //initialize three sensors. These come from a class "Sensors.h" TODO

    //Deal with pin modes
    pinMode(BUZZER_PIN,OUTPUT);

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
    logFile.println("index,Sensor1,Sensor2,Sensor3");
    logFile.close();

    //play startup beep TODO

    while (millis() < 5000) {} //Just waits until the system has been on for 5 seconds
}

void loop() {
    //read from sensors
    //write to SD card
    //play action complete beep
    //wait until next time
}