#include "../include/Shop.h"

Shop::Shop()
{
    std::vector<std::pair<int,int>> gains;
    gains.push_back(std::make_pair(2, 2));
    Item* drink = new Item("Cola", CONSUMABLE, HEAL, DRINK, gains);

    
    gains.clear();
    gains.push_back(std::make_pair(1, 2));
    gains.push_back(std::make_pair(2, 2));
    Item* beans = new Item("BEANS", CONSUMABLE, HEAL, FOOD, gains);

    gains.clear();
    Item* revolver = new Item("REVOLVER GUN", USABLE, GUN, PRIMARY_GUN, gains);

    gains.clear();
    Item* riffle = new Item("RIFFLE GUN", USABLE, GUN, SECONDARY_GUN, gains);

    sellingItems.push_back(std::make_pair(drink, 1.5));
    sellingItems.push_back(std::make_pair(beans, 2.0));
    sellingItems.push_back(std::make_pair(revolver, 5.0));
    sellingItems.push_back(std::make_pair(riffle, 7.0));
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