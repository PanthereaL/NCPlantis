#include <Arduino.h>

//pin defines
int RGB_RED = 0;
int RGB_GREEN = 1;
int RGB_BLUE = 2;

//function declaration

//global variables

void setup() {
    Serial.begin(9600);
    pinMode(RGB_RED,OUTPUT);
    pinMode(RGB_GREEN,OUTPUT);
    pinMode(RGB_BLUE,OUTPUT);
    pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
    for (int i = 0 ; i < 8 ; i++) {
        digitalWrite(RGB_RED,i & 0b100);
        digitalWrite(RGB_GREEN, i & 0b010);
        digitalWrite(RGB_BLUE, i & 0b001);
        digitalWrite(LED_BUILTIN, i & 0b001);
        delay(1000);
    }
}