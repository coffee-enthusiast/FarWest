#include "GameEngine.h"
#include "../include/Map.h"
#include "../../UF/include/Factories.h"
#include <iostream>
#include <time.h> 
#include "../../UI/include/IOFunctions.h"
#include "../../UI/include/Trace.h"

GameEngine::GameEngine()
{
    IPlayer* player = Factories::createPlayer();
    Map* worldMap = new Map(player);

    std::vector<IPlace*> places;
    places.push_back(Factories::createHome(worldMap));

    Shop* shop = new Shop();
    places.push_back(Factories::createShop(worldMap, shop));
    places.push_back(Factories::createMine(worldMap));

    worldMap->SetPlaces(places);
    worldMap->ChangePlace(0);
    
    currDay = 1;
    InitUI();
    fOut("Welcome cowboy!");

    while(player->getPlayerAction() != 5 && player->isPlayerAlive() == true)
    {
        fOut("Day: " + std::to_string(currDay));
        currDay++;
        player->printStats();
        worldMap->currentPlace->PromptInput();
        worldMap->currentPlace->ReadInput();

    }

}

//  Simulates gunfight
//  returns -1 if player loses
int GameEngine::gunFight(IPlayer* p)
{
    srand(time(0));
    int chance = rand() % 10;
    if(chance <= p->getShootingDamage())
    {
        
        p->useSkill(SHOOTING);
        fOut("You Win!");
        return 0;
    }
    else
    {
        p->useSkill(SHOOTING);
        fOutWarn("You Lose!");
        return -1;
    }
}

int GameEngine::simulateDay(IPlayer* p)
{
    srand(time(0));
    int chance = rand() % 10;
    // Bad luck
    if(chance <= 3)
    {
        fOutWarn("!Bad luck!");
        if(p->getNumberOfGuns() == 0)
        {
            fOutWarn("You died!");
            p->setPlayerAlive(false);
        }
        else
        {
            int result = gunFight(p);
            switch(result)
            {
                case -1:
                    p->addHealth(-5);
                    fOutWarn("Ouch! -5 Health!");
                    break;
                default:
                    break;
            }
        }

        if(p->getHealth() == 0)
        {
            p->setPlayerAlive(false);
        }
        return 1;
    }
    return 0;
}