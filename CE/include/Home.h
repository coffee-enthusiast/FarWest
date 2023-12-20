#pragma once

#include "Room.h"
#include "../../UF/include/EntitiesInterfaces.h"

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

class HomePlace: public IPlace
{
public:
    HomePlace(IMap* map);
    std::vector<int> PrintRoutes();
    //  Place virtual methods
    void EnterPlace(IPlayer* player);
    void PromptInput();
    void ReadInput();
    void ExitPlace();
};