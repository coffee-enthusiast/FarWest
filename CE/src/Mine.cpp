#include "../include/Mine.h"

Mine::Mine(int amountLeft, int totalAmount)
{
    this->amountLeft = amountLeft;
    this->totalAmount = totalAmount;
}
MinePlace::MinePlace(IMap* map)
{
    this->map = map;
    this->placeTag = HOME;
}

//  Place virtual methods
void MinePlace::EnterPlace()
{
    fOut("==========MINE==========");
}

void MinePlace::PromptInput()
{
    fOut("Press 1: Start working");
    fOut("Press 2: Leave Shop");
}

void MinePlace::ReadInput()
{
    int input = -1;

    fInInt(&input);

    switch(input)
    {
        case 1: //  Work
            break;
        case 2: //  Leave
            break;
        default:
            break;
    }
}

void MinePlace::ExitPlace()
{

    fOut("==========LEAVING MINE==========");
}