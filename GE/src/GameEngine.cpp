#include "GameEngine.h"
#include "../../UF/include/PlayerFactory.h"
#include <iostream>
#include "../../UI/include/IOFunctions.h"
#include "../../UI/include/Trace.h"

GameEngine::GameEngine()
{
    IPlayer* player = PlayerFactory::createPlayer();
    currDay = 1;
    fOut("Welcome cowboy!");

    while(player->getPlayerAction() != 5 && player->isPlayerAlive() == true)
    {
        fOut("Day: " + std::to_string(currDay));
        currDay++;
        player->printStats();
        prompt();
        for(int i = 0; i < 3; i++)
        {
            fOut("Action(" + std::to_string((i+1)) + "/3):");
            readInput();
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

int GameEngine::gunFight(IPlayer* p)
{
    return -1;
}

int GameEngine::simulateDay(IPlayer* p)
{
    srand(time(0));
    int chance = rand() % 10;
    fTrace("Chance: " + std::to_string(chance));
    // Bad luck
    if(chance <= 3)
    {
        fTrace("Bad luck!");
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