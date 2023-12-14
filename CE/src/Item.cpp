#include "../include/Item.h"

Item::Item(std::string itemName, ItemType itemType, std::vector<std::pair<int,int>> gains)
{
    this->itemName = itemName;
    this->itemType = itemType;
    this->gains = gains;
}

