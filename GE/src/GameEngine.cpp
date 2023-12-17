#include "GameEngine.h"
#include "../include/Map.h"
#include "../../UF/include/PlayerFactory.h"
#include <iostream>
#include <time.h> 
#include "../../UI/include/IOFunctions.h"
#include "../../UI/include/Trace.h"

GameEngine::GameEngine()
{
    Map* worldMap = new Map();
    IPlayer* player = PlayerFactory::createPlayer();
    std::vector<IPlace*> places;
    places.push_back(HomeFactory::createHome(worldMap));
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
        for(int i = 0; i < 3; i++)
        {
            fOut("Action(" + std::to_string((i+1)) + "/3):");
            int userInput = -1;
            fInInt(&userInput);
            player->setPlayerAction(userInput);
            processInput(player);
            player->simulateAction();
            player->printStats();
            //  If sleeps
            if(player->getPlayerAction() == 4)
                break;
        }
        simulateDay(player);
        //  If not sleeping
        if(player->getPlayerAction() != 4)
            player->goToSleep();
    }

}

//  Simulates gunfight
//  returns -1 if player loses
int GameEngine::gunFight(IPlayer* p)
{
    srand(time(0));
    int chance = rand() % 10;
    if(chance <= p->getDamage())
    {
        fOut("You Win!");
        return 0;
    }
    else
    {
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