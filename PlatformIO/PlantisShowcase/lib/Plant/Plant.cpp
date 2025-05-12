#include "Plant.h"

Plant::Plant(std::string n, LightLevel light, MoistureLevel moisture): 
name(n), preferredLightLevel(light), preferredMoistureLevel(moisture) {}

MoistureLevel convertToMLevel(int raw)
{
    if (raw < 200) return VERY_DRY;
    else if (raw < 400) return DRY;
    else if (raw < 600) return MEDIUM_MOIST;
    else if (raw < 800) return WET;
    else return VERY_WET;
}

LightLevel convertToLLevel(int raw)
{
    if (raw < 200) return VERY_DARK;
    else if (raw < 400) return DARK;
    else if (raw < 600) return MEDIUM_LIGHT;
    else if (raw < 800) return BRIGHT;
    else return VERY_BRIGHT;
}
