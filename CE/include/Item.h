#pragma once
#include <string>
#include <vector>
#include "../../UF/include/EntitiesInterfaces.h"
enum ItemType
{
    CONSUMABLE,
    WEARABLE,
    USABLE
};

class Item
{
public:
    std::string itemName;
    ItemType itemType;
    std::vector<std::pair<int,int>> gains;

    Item(std::string itemName, ItemType itemType, std::vector<std::pair<int,int>> gains);
};