#include "../include/Shop.h"

#include "../../UI/include/IOFunctions.h"
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

ShopPlace::ShopPlace(IMap* map)
{
    this->map = map;
    this->placeTag = HOME;
}

//  Place virtual methods
void ShopPlace::EnterPlace()
{
    fOut("==========SHOP==========");
}

void ShopPlace::PromptInput()
{
    fOut("Press 1: Buy");
    fOut("Press 2: Sell");
    fOut("Press 3: Leave Shop");
}

void ShopPlace::ReadInput()
{
    int input = -1;

    fInInt(&input);

    switch(input)
    {
        case 1: //  Buy
            break;
        case 2: //  Sell
            break;
        case 3: //  Leave
            break;
        default:
            break;
    }
}

void ShopPlace::ExitPlace()
{

    fOut("==========LEAVING SHOP==========");
}