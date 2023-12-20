#include "Home.h"

#include "../../UI/include/IOFunctions.h"
#include <list>
#include <vector>
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

std::vector<int> HomePlace::PrintRoutes()
{
    std::vector<int> availRoutes = map->GetRoutes(placeTag);
    fOut("Available routes:");
    if(availRoutes.size() == 0)
    {
        fOut("-NONE-");
        return availRoutes;
    }

    for(int i = 0; i < availRoutes.size(); i++)
    {
        fOut(std::to_string(i + 1) + "\t" + std::to_string((PlaceTag)availRoutes[i]));
    }

    return availRoutes;
}

//  Place virtual methods
void HomePlace::EnterPlace(IPlayer* player)
{
    this->player = player;
    fOut("==========HOME==========");
}

void HomePlace::PromptInput()
{
    fOut("Press 1: Go To Sleep");
    fOut("Press 2: Leave Home");
}

void HomePlace::ReadInput()
{
    if(player == nullptr)
        return;
        
    int input = -1;

    fInInt(&input);

    switch(input)
    {
        case 1: //  Sleep
            map->player->goToSleep();
            break;
        case 2: //  Leave
        {
            std::vector<int> choose = PrintRoutes();
            fInInt(&input);
            map->ChangePlace(choose[input-1]);
            break;
        }
        default:
            break;
    }
}

void HomePlace::ExitPlace()
{
    this->player = nullptr;
    fOut("==========LEAVING HOME==========");
}