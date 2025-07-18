#include <Arduino.h>
#include "SPI.h"
#include "RF24.h"
#include "Plant.h"

RF24 radio (20, 17); //CE, CNS
const byte address[6] = "00001"; //Address of receiver

Plant myPlant("Monstera",MEDIUM_LIGHT,MEDIUM_MOIST);

int MOISTURE_SENSOR_PIN = A0;
int MOISTURE_ENABLE_PIN = 0;
int LIGHT_SENSOR_PIN1 = A1;
int LIGHT_SENSOR_ENABLE_PIN = 1;
int BUTTON_PIN_PLUS;
int BUTTON_PIN_MINUS;
int BUTTON_PIN_SELECT;
int RGB_PINS[4][3] = {  //Pins for the RGB leds, sorted {R,G,B}.
  {2,3,4},
  {5,6,7},
  {8,9,10},
  {11,12,13}
};

enum OutputState {
  WATER,
  LIGHT,
  BATTERY,
  NUM_STATES
};

enum OutputLevel { 
  VERY_LOW, //Corresponds to 0-25%
  LOW, //Corresponds to 25-50%
  MEDIUM,
  HIGH, // Corresponds to 50-75%
  VERY_HIGH, //Corresponds to 75-100%
  NUM_STATES
};

bool newInstructions = false;
uint16_t currTime;

// put function declarations here:
//Functions that handle sensor readings
int readMoisture(int enable, int read);
int readLight(int enable, int read);

//Procedures that handle radio
void radioInit(const byte addr[6]);
bool radioSend(std::string text);

//Procedures concerning user interaction
void menuStart(Plant plant);
void inputControl(Plant plant);
void outputStart(Plant plant);

void setup() {
  Serial.begin(9600);
  delay(2000);
  //Set up pins
  pinMode(MOISTURE_ENABLE_PIN, OUTPUT);
  digitalWrite(MOISTURE_ENABLE_PIN,LOW);
  pinMode(LIGHT_SENSOR_ENABLE_PIN, OUTPUT);
  digitalWrite(LIGHT_SENSOR_ENABLE_PIN,LOW);
  pinMode(BUTTON_PIN_MINUS,INPUT_PULLDOWN);
  pinMode(BUTTON_PIN_PLUS,INPUT_PULLDOWN);
  pinMode(BUTTON_PIN_SELECT,INPUT_PULLDOWN);
  for (int i = 0; i < 4; i++) { //RGB-LED pins
    for (int j = 0; j < 3; j++) {
        pinMode(RGB_PINS[i][j], OUTPUT);
        digitalWrite(RGB_PINS[i][j],LOW);
    }
  }

  Serial.println("Serial opened");
  //Initializing radio
  radioInit(address);
}

void loop() {
  currTime = millis();
  myPlant.currentMoistureValue = readMoisture(MOISTURE_ENABLE_PIN,MOISTURE_SENSOR_PIN); //~10 seconds
  myPlant.currentLightValue = readLight(LIGHT_SENSOR_ENABLE_PIN,LIGHT_SENSOR_PIN1); //~0.2 seconds

  Serial.println(myPlant.currentMoistureValue, myPlant.currentLightValue);

  if (newInstructions) {
    radioSend("Mode two");
    radioSend(std::to_string(myPlant.preferredMoistureLevel));
    radioSend(std::to_string(myPlant.preferredLightLevel));
    newInstructions = false;
  } else {
    radioSend("Mode one");
  }
  radioSend(std::to_string(myPlant.currentMoistureValue)); //unknown time
  radioSend(std::to_string(myPlant.currentLightValue)); //unknown time

  while(millis() < currTime + 1800000) {
    if (digitalRead(BUTTON_PIN_SELECT)) {
      //inputControl(myPlant);
    }
  }; //1800 sekunder, 30 minutter
}

// put function definitions here:
int readMoisture(int enable, int read){
  digitalWrite(enable,HIGH);
  delay(10000); //Let the sensor wake up
  int reading = analogRead(read); //Just in case reading clears something up, the first reading tends to be garbage
  reading = analogRead(read);
  digitalWrite(enable,LOW);
  return reading;
}

int readLight(int enable, int read){
  digitalWrite(LIGHT_SENSOR_ENABLE_PIN,HIGH);
  delay(200); //Let the sensor warm up. I don't know if this is enough
  int reading = analogRead(LIGHT_SENSOR_PIN1);
  digitalWrite(LIGHT_SENSOR_ENABLE_PIN,LOW);
  return reading;
}

void radioInit(const byte addr[6]){ //This should ideally be brought out into a Radio module
  bool connected = radio.begin(); 
  if (connected) {
    Serial.println("Successfully initialized radio tranceiver.");
  } else {
    Serial.println("Failed to initialize radio tranceiver.");
  }
  radio.openWritingPipe(addr);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

bool radioSend(std::string text){ //This should ideally be brought out into a Radio module
  bool success = false;
  int sendCounter = 0;
  int maxSends = 20;
  while(!success) {
    success = radio.write(&text, sizeof(text));
    sendCounter++;
    if(sendCounter>maxSends){
      break;
    }
  }
  if (success) {
    Serial.println("Sent successfully");
  } else {
    Serial.println("Failed to send.");
  }
  return success;
}

void menuStart(Plant plant){
  bool shouldContinue = false;
  MoistureLevel mSetting = plant.preferredMoistureLevel;
  LightLevel lSetting = plant.preferredLightLevel;
  uint16_t referenceTime = millis();
  //Blink blue twice
  while (millis() < referenceTime + 10000) {
    if (digitalRead(BUTTON_PIN_PLUS)) {
      mSetting = static_cast<MoistureLevel>((mSetting +1) % NUM_STATES);
      referenceTime = millis();
    } else if (digitalRead(BUTTON_PIN_MINUS)) {
      mSetting = static_cast<MoistureLevel>((mSetting + NUM_STATES -1) % NUM_STATES);
      referenceTime = millis();
    } else if (digitalRead(BUTTON_PIN_SELECT)) {
      referenceTime = millis();
      while ((millis() < referenceTime + 500) && digitalRead(BUTTON_PIN_SELECT)){}
      referenceTime = millis();
      if (digitalRead(BUTTON_PIN_SELECT)) {
        shouldContinue = true;
      }
    }
    if (shouldContinue) {
      break;
    }
  }
  if (!shouldContinue) {
    //Three short red blinks
    return;
  }
  //Two yellow blinks
  while (millis() < referenceTime + 10000) {
    if (digitalRead(BUTTON_PIN_PLUS)) {
      lSetting = static_cast<LightLevel>((lSetting +1) % NUM_STATES);
      referenceTime = millis();
    } else if (digitalRead(BUTTON_PIN_MINUS)) {
      lSetting = static_cast<LightLevel>((lSetting + NUM_STATES -1) % NUM_STATES);
      referenceTime = millis();
    } else if (digitalRead(BUTTON_PIN_SELECT)) {
      referenceTime = millis();
      while ((millis() < referenceTime + 500) && digitalRead(BUTTON_PIN_SELECT)){}
      referenceTime = millis();
      if (digitalRead(BUTTON_PIN_SELECT)) {
        shouldContinue = true;
      }
    }
    if (shouldContinue) {
      break;
    }
  }
  if (!shouldContinue) {
    //Three short red blinks
    return;
  } else {
    plant.preferredLightLevel = lSetting;
    plant.preferredMoistureLevel = mSetting;
    newInstructions = true;
    //Two green blinks
    return;
  }

}

void inputControl(Plant plant){
  uint32_t referenceTime = millis();
  while(digitalRead(BUTTON_PIN_SELECT) && millis() < referenceTime + 500) {
  }
  if (digitalRead(BUTTON_PIN_SELECT)) {
    menuStart(plant);
  } else {
    outputStart(plant);
  }
}

void outputStart(Plant plant){
  uint32_t referenceTime = millis();
  OutputState state = WATER;
  OutputLevel waterLevel;
  OutputLevel batteryLevel;
  OutputLevel lightLevel;
  while (millis() < referenceTime + 10000) //10 second timeout
  {
    //state decides light color, and which output level to display
    //pressing plus or minus changes state
    switch (state)
    {
    case WATER: //Not sure a switch case is the best way to handle this. Or even a good one.
      switch (waterLevel)
      {
      case VERY_LOW:
        //LED1 RGB_BLUE_FLASH
        break;
      
      case LOW:
        //LED1 RGB_BLUE_ON
        //LED2 RGB_BLUE_FLASH
        break;
      
      default:
        break;
      }
      break;
    
    default:
      break;
    }
  }
  return;
  //Blue lights indicative of water level, current sector flashes, sectors under are lit, sectors over are dark
  //+
  //Yellow lights indicate light level
  //+
  //Green lights indicate battery level
  //+
  //Blue lights etc.
}
