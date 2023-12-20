#include "../include/Mine.h"
#include "../../UI/include/IOFunctions.h"

Mine::Mine(int amountLeft, int totalAmount)
{
    this->amountLeft = amountLeft;
    this->totalAmount = totalAmount;
}
MinePlace::MinePlace(IMap* map)
{
    this->map = map;
    this->placeTag = MINE;
}

std::vector<int> MinePlace::PrintRoutes()
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
void MinePlace::EnterPlace(IPlayer* player)
{
    this->player = player;
    fOut("==========MINE==========");
}

void MinePlace::PromptInput()
{
    fOut("Press 1: Start working");
    fOut("Press 2: Leave Mine");
}

void MinePlace::ReadInput()
{
    if(player == nullptr)
        return;
    int input = -1;

    fInInt(&input);

    switch(input)
    {
        case 1: //  Work
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

void MinePlace::ExitPlace()
{
    this->player = nullptr;
    fOut("==========LEAVING MINE==========");
}