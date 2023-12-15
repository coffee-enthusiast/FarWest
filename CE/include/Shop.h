#pragma once
#include <vector>
#include "Item.h"

class Shop
{
public:
    //  Format: <Item, Price>
    std::vector<std::pair<Item*, float>> sellingItems;
    Shop();
    Shop(std::vector<std::pair<Item*, float>> sellingItems);
    Item* BuyItem(int position, float* playerCash);
    float GetPriceItem(int position);
};