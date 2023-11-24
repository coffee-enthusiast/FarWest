#include "IOFunctions.h"

#include "ActionAttributes.h"

#include <iostream>
int playerInput;
void prompt()
{
    std::cout << "Press 1: Work\t\t(+$2,\t" << workStamina << " Stamina,\t" << workHealth << " Health)"<< std::endl
        << "Press 2: Drink Cola\t(+2 Stamina, -$1)" << std::endl
        << "Press 3: Eat Beans\t(+2 Stamina, +2 Health, -$2)" << std::endl
        << "Press 4: Buy Gun\t(+1 Gun,\t-$5)" << std::endl
        << "Press 5: Sleep\t\t(+" << sleepStamina <<" Stamina,\t+"<<sleepHealth<<" Health)" << std::endl
        << "Press 6: Exit" << std::endl;
        
    std::cout << "-----------------------------------------------------" << std::endl;
}

int readInput()
{
    std::cin >> playerInput;
    return playerInput;
}

void processInput(Player* p)
{
    switch(playerInput)
    {
        case 1:
            p->playerAction = WORK;
            break;
        case 2:
            p->playerAction = DRINK;
            break;
        case 3:
            p->playerAction = EAT;
            break;
        case 4:
            p->playerAction = BUY_GUN;
            break;
        case 5:
            p->playerAction = SLEEP;
            break;
        case 6:
            p->playerAction = EXIT;
            break;
        default:
            break;
    }
}