#include "Home.h"

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