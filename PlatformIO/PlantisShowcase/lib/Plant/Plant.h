#ifndef PLANT_H
#define PLANT_H

#include <string>

//Unique definitions:

//Structures
enum MoistureLevel {
    VERY_DRY,
    DRY,
    MEDIUM,
    WET,
    VERY_WET
};

enum LightLevel {
    VERY_DARK,
    DARK,
    MEDIUM,
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