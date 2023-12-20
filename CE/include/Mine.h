#pragma once

#include <vector>
#include "../../UF/include/EntitiesInterfaces.h"
#include "Item.h"

class Mine
{
public:
    int totalAmount;
    int amountLeft;
    Mine();
    Mine(int amountLeft, int totalAmount);
    
    Item* Work(int miningDamage);
};


class MinePlace: public IPlace
{
public:
    MinePlace(IMap* map);
    Mine* mine;
    std::vector<int> PrintRoutes();
    //  Place virtual methods
    void EnterPlace(IPlayer* player);
    void PromptInput();
    void ReadInput();
    void ExitPlace();
};