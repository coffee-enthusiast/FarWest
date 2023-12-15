#include "IOFunctions.h"

#include "../../UF/include/ActionAttributes.h"
#include "../../UF/include/EntitiesInterfaces.h"

#include <stdio.h>
#include "conio.h"
#include <iostream>
#include <windows.h>
int playerInput;
void prompt()
{
    std::cout << "Press 1: Work\t\t(+$2,\t" << workStamina << " Stamina,\t" << workHealth << " Health)"<< std::endl
        << "Press 2: Drink Cola\t(+2 Stamina, -$1)" << std::endl
        << "Press 3: Eat Beans\t(+2 Stamina, +2 Health, -$2)" << std::endl
        << "Press 4: Buy Gun\t(+1 Gun,\t-$5)" << std::endl
        << "Press 5: Sleep\t\t(+" << sleepStamina <<" Stamina,\t+"<<sleepHealth<<" Health)" << std::endl
        << "Press 6: Exit" << std::endl
        << "Press 7[index]: Use item from inventory" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
}

void fInInt(int* storeInput)
{
    std::cin >> (*storeInput);
    return;
}

enum COLORS
{
	TEXT_BLACK=0x00, TEXT_BLUE=0x01, TEXT_GREEN=0x02, TEXT_CYAN=0x03,
	TEXT_RED=0x04, TEXT_MAGENTA=0x05, TEXT_BROWN=0x06, TEXT_LIGHTGRAY=0x07,
	TEXT_DARKGRAY=0x08, TEXT_LIGHTBLUE=0x09, TEXT_LIGHTGREEN=0x0A, TEXT_LIGHTCYAN=0x0B,
	TEXT_LIGHTRED=0x0C, TEXT_LIGHTMAGENTA=0x0D, TEXT_YELLOW=0x0E, TEXT_WHITE=0x0F,

	BACK_BLACK=0x00, BACK_BLUE=0x10, BACK_GREEN=0x20, BACK_CYAN=0x30,
	BACK_RED=0x40, BACK_MAGENTA=0x50, BACK_BROWN=0x60, BACK_LIGHTGRAY=0x70,
	BACK_DARKGRAY=0x80, BACK_LIGHTBLUE=0x90, BACK_LIGHTGREEN=0xA0, BACK_LIGHTCYAN=0xB0,
	BACK_LIGHTRED=0xC0, BACK_LIGHTMAGENTA=0xD0, BACK_YELLOW=0xE0, BACK_WHITE=0xF0,
};

void InitUI()
{
	SetConsoleTextAttribute ( GetStdHandle(STD_OUTPUT_HANDLE), (TEXT_WHITE + BACK_BLACK));
}

void fOut(std::string message)
{
    printf("%s\n", message.c_str());
}

void fOutWarn(std::string message)
{

	/*
	* Set the new color information
	*/
	SetConsoleTextAttribute ( GetStdHandle(STD_OUTPUT_HANDLE), (TEXT_RED + BACK_BLACK));
	printf ( "%s\n", message.c_str());
    /*
	* Restore the original colors
	*/
    
    InitUI();
}
void fOutSucc(std::string message)
{
    /*
	* Set the new color information
	*/
	SetConsoleTextAttribute ( GetStdHandle(STD_OUTPUT_HANDLE), (TEXT_GREEN + BACK_BLACK));
	printf ( "%s\n", message.c_str());
    /*
	* Restore the original colors
	*/
    
    InitUI();
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