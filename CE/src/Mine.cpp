#include "../include/Mine.h"
#include "../../UI/include/IOFunctions.h"
#include <time.h>

Mine::Mine(int amountLeft, int totalAmount)
{
    this->amountLeft = amountLeft;
    this->totalAmount = totalAmount;
}

Item* Mine::Work(int miningDamage)
{
    if(amountLeft == 0)
        return nullptr;

    srand(time(0));
    amountLeft -= miningDamage;
    if(amountLeft < 0)
        amountLeft = 0;

    int randomRock = rand() % 3;
    Item* rock = new Item(std::string("Rock"), USABLE, (ItemCategory)ROCK, (ItemSubCategory) (6 + randomRock), std::vector<std::pair<int,int>>());
    return rock;
}

MinePlace::MinePlace(IMap* map)
{
    this->map = map;
    this->placeTag = MINE;

    this->mine = new Mine(100,100);

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
        {
            Item* rock = mine->Work(player->getMiningDamage());
            if(rock == nullptr)
            {
                fOut("Work didn't go as planned!");
                return;
            }
            fOut("Earned a " + std::to_string(rock->itemSubCategory) + " " + rock->itemName);
            player->useSkill(MINING);
            player->addItem(rock);
            break;
        }
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