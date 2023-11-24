#pragma once

#include "Room.h"

class Home
{
    int safetyLevel;
    int maxGuns;
    Room bedroom;
    Room kitchen;
    // Updates costs
    int safetyUpdateCost;
    int maxGunsUpdateCost;
public:
    Home();
};
