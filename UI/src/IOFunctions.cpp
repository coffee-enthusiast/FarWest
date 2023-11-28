#include "IOFunctions.h"

#include "../../UF/include/ActionAttributes.h"
#include "../../UF/include/EntitiesInterfaces.h"

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

void processInput(IPlayer* p)
{
    switch(playerInput)
    {
        case 1:
            //  WORK
            p->setPlayerAction(0);
            break;
        case 2:
            //  DRINK
            p->setPlayerAction(1);
            break;
        case 3:
            //  EAT
            p->setPlayerAction(2);
            break;
        case 4:
            //  BUY_GUN
            p->setPlayerAction(3);
            break;
        case 5:
            //  SLEEP
            p->setPlayerAction(4);
            break;
        case 6:
            //  EXIT
            p->setPlayerAction(5);
            break;
        default:
            break;
    }
}