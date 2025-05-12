#ifndef PLANT_H
#define PLANT_H

#include <string>

//Unique definitions:

//Structures
enum MoistureLevel {
    VERY_DRY,
    DRY,
    MEDIUM_MOIST,
    WET,
    VERY_WET,
    NUM_STATES //A functional element to allow easier rolling. It should not show up or be set explicitly.
};

enum LightLevel {
    VERY_DARK,
    DARK,
    MEDIUM_LIGHT,
    BRIGHT,
    VERY_BRIGHT
};

struct Plant {
    std::string name;
    LightLevel preferredLightLevel;
    MoistureLevel preferredMoistureLevel;
    int currentLightValue; //This is set directly from the sensor readings
    int currentMoistureValue; //This is set directly from the sensor readings
  
    Plant::Plant(std::string n, LightLevel light, MoistureLevel moisture);
};

//Functions
MoistureLevel convertToMLevel(int raw);
LightLevel convertToLLevel(int raw);

#endif