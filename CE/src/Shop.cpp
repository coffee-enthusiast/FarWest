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

ShopPlace::ShopPlace(IMap* map, Shop* shop)
{
    this->map = map;
    this->placeTag = SHOP;

    this->shop = shop;
}

std::vector<int> ShopPlace::PrintRoutes()
{
    std::vector<int> availRoutes = map->GetRoutes(placeTag);
    fOut("Available routes:");
    if(availRoutes.size() == 0)
    {
        fOut("-NONE-");
        return availRoutes;
    }

    for(int i = 0; i < availRoutes.size(); i++)
    {
        fOut(std::to_string(i + 1) + "\t" + std::to_string((PlaceTag)availRoutes[i]));
    }

    return availRoutes;
}

//  Place virtual methods
void ShopPlace::EnterPlace(IPlayer* player)
{
    this->player = player;
    fOut("==========SHOP==========");
}

void ShopPlace::PromptInput()
{
    fOut("Press 1: Buy");
    fOut("Press 2: Sell");
    fOut("Press 3: Leave Shop");
}

void Shop::PrintSellingItems()
{

}

void ShopPlace::ReadInput()
{
    if(player == nullptr)
        return;

    int input = -1;

    fInInt(&input);

    switch(input)
    {
        case 1: //  Buy
            shop->PrintSellingItems();
            break;
        case 2: //  Sell
            break;
        case 3: //  Leave
        {
            std::vector<int> choose = PrintRoutes();
            fInInt(&input);
            map->ChangePlace(choose[input-1]);
            break;
        }
        default:
            break;
    }
}

void ShopPlace::ExitPlace()
{
    this->player = nullptr;
    fOut("==========LEAVING SHOP==========");
}