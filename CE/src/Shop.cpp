#include "../include/Shop.h"

Shop::Shop()
{
    std::vector<std::pair<int,int>> gains;
    gains.push_back(std::make_pair(2, 2));
    Item* drink = new Item("Cola", CONSUMABLE, gains);

    
    gains.clear();
    gains.push_back(std::make_pair(1, 2));
    gains.push_back(std::make_pair(2, 2));
    Item* beans = new Item("BEANS", CONSUMABLE, gains);

    sellingItems.push_back(std::make_pair(drink, 1.5));
    sellingItems.push_back(std::make_pair(beans, 2.0));
}

Shop::Shop(std::vector<std::pair<Item*, float>> sellingItems)
{
    this->sellingItems = sellingItems;
}
Item* Shop::BuyItem(int position, float* playerCash)
{
    if(position >= sellingItems.size())
        return nullptr;

    if(*playerCash < this->sellingItems[position].second)
        return nullptr;

    *playerCash -= this->sellingItems[position].second;
    return this->sellingItems[position].first;
}

float Shop::GetPriceItem(int position)
{
    if(position >= sellingItems.size())
        return -1;
    
    return this->sellingItems[position].second;
}