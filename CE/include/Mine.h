#pragma once

#include <vector>
#include "../../UF/include/EntitiesInterfaces.h"

class Mine
{
public:
    int totalAmount;
    int amountLeft;
    Mine();
    Mine(int amountLeft, int totalAmount);
    
};


class MinePlace: public IPlace
{
public:
    MinePlace(IMap* map);
    std::vector<int> PrintRoutes();
    //  Place virtual methods
    void EnterPlace(IPlayer* player);
    void PromptInput();
    void ReadInput();
    void ExitPlace();
};