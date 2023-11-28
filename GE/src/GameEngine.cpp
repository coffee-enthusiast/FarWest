#include "GameEngine.h"
#include "../../UF/include/PlayerFactory.h"
#include <iostream>
#include "../../UI/include/IOFunctions.h"
#include "../../UI/include/Trace.h"

GameEngine::GameEngine()
{
    IPlayer* player = PlayerFactory::createPlayer();
    currDay = 1;
    std::cout << "Welcome cowboy!" << std::endl;

    while(player->getPlayerAction() != 5 && player->isPlayerAlive() == true)
    {
        std::cout << "Day: " << currDay++ << std::endl;
        player->printStats();
        prompt();
        for(int i = 0; i < 3; i++)
        {
            fTrace("Action:");
            std::cout << "Action(" << (i+1) << "/3):" << std::endl;
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
    return 1;
}

int GameEngine::simulateDay(IPlayer* p)
{
    srand(time(0));
    int chance = rand() % 10;

    // Bad luck
    if(chance <= 3)
    {
        fTrace("Bad luck!");
        std::cout << "!Bad luck!" << std::endl;
        if(p->getNumberOfGuns() == 0)
        {
            std::cout << "You died!" << std::endl;
            p->setPlayerAlive(false);
        }
        else
        {
            int result = gunFight(p);
            switch(result)
            {
                
            }
        }
        return 1;
    }
    return 0;
}