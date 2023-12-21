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

float Shop::GetItemPrice(int position)
{
    if(position >= sellingItems.size())
        return -1;

    return sellingItems[position].second;
}

Item* Shop::BuyItem(int position)
{
    if(position >= sellingItems.size())
        return nullptr;

    
    return this->sellingItems[position].first;
}

float Shop::SellItem(Item* item)
{
    switch(item->itemSubCategory)
    {
        case 6: //  GOLD
            return 2.0;
        case 7: //  DIAMOND
            return 5.0;
        default:
            break;
    }

    return -1;
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
    fOut("Items:");
    for(int i = 0; i < sellingItems.size(); i++)
    {
        std::pair<Item *, float > pair = sellingItems[i];
        fOut(std::to_string(i) + ")\t" + pair.first->itemName + "\t$" + std::to_string(pair.second));
    }
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
        {
            shop->PrintSellingItems();
            fInInt(&input);
            float itemPrice = shop->GetItemPrice(input);
            if(itemPrice > player->totalMoney())
            {
                fOut("Not enough money to buy item!");
                break;
            }
            Item* itemToBuy = shop->BuyItem(input);
           
            player->addMoney(-itemPrice);
            player->addItem(itemToBuy);
            fOut(itemToBuy->itemName + " purchased!");
            break;
        }
        case 2: //  Sell
        {
            fOut("Choose item from your inventory:");
            player->printItemsInventory();
            fInInt(&input);
            Item* itemToSell = player->getItemFromInventory(input);
            float itemOfferedPrice = shop->SellItem(itemToSell);
            if(itemOfferedPrice > 0)
            {
                player->addMoney(itemOfferedPrice);
            }
            player->discardItemFromInventory(input);
            
            fOut(itemToSell->itemName + " sold for $" + std::to_string(itemOfferedPrice));
           
            break;
        }
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