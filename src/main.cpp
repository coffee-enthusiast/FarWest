#include <iostream>
#include <cstdlib>
#include <time.h>  
#include <fstream>
#include <chrono>
#include <string>

//  Built-in headers
#include "IOFunctions.h"
#include "Trace.h"
#include "Room.h"
#include "ActionAttributes.h"
#include "Player.h"
using namespace std;

//  Global tracing boolean
bool isTracingActive;


int currDay = 1;



    


int simulateDay(Player* p)
{
    srand(time(0));
    int chance = rand() % 10;

    // Bad luck
    if(chance <= 3)
    {
        fTrace("Bad luck!");
        std::cout << "!Bad luck!" << endl;
        if(p->numberOfGuns == 0)
        {
            std::cout << "You died!" << endl;
            p->alive = false;
        }
        else
        {
            p->numberOfGuns--;
        }
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    //  Activate tracing
    if (argc > 1 && std::string(argv[1]) == "-trace") 
    {
        std::cout << "Traces argument found!" << endl;
        isTracingActive = true;
        InitTracing();
    }
    else
    {
        isTracingActive = false;
    }
    Player player = Player();
    std::cout << "Welcome cowboy!" << endl;

    while(player.playerAction != EXIT && player.alive == true)
    {
        std::cout << "Day: " << currDay++ << endl;
        player.printStats();
        prompt();
        for(int i = 0; i < 3; i++)
        {
            fTrace("Action:");
            std::cout << "Action(" << (i+1) << "/3):" << endl;
            readInput();
            processInput(&player);
            player.simulateAction();
            player.printStats();
            if(player.playerAction == SLEEP)
                break;
        }
        simulateDay(&player);
        player.goToSleep();
    }

    return 0;
}