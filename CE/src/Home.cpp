#include "Home.h"

#include "../../UI/include/IOFunctions.h"
#include <list>
Home::Home()
{
    safetyLevel = 0;
    maxGuns     = 0;

    safetyUpdateCost    = 3;
    maxGunsUpdateCost   = 4;

    bedroom = Room(BEDROOM, 1, std::list<RoomLevel>());
    kitchen = Room(KITCHEN, 1, std::list<RoomLevel>());

}

HomePlace::HomePlace(IMap* map)
{
    this->map = map;
    this->placeTag = HOME;
}

//  Place virtual methods
void HomePlace::EnterPlace()
{
    fOut("==========HOME==========");
}

void HomePlace::PromptInput()
{
    fOut("Press 1: Go To Sleep");
    fOut("Press 2: Leave Home");
}

void HomePlace::ReadInput()
{
    int input = -1;

    fInInt(&input);

    switch(input)
    {
        case 1: //  Sleep
            break;
        case 2: //  Leave
            break;
        default:
            break;
    }
}

void HomePlace::ExitPlace()
{

    fOut("==========LEAVING HOME==========");
}