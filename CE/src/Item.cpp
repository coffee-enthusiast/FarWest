#include "../include/Item.h"

Item::Item(std::string itemName, 
            ItemType itemType, 
            ItemCategory itemCategory, 
            ItemSubCategory itemSubCategory, 
            std::vector<std::pair<int,int>> gains)
{
    this->itemName = itemName;
    this->itemType = itemType;
    this->itemCategory = itemCategory;
    this->itemSubCategory = itemSubCategory;
    this->gains = gains;
}

