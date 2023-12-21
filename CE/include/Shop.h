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
    float GetItemPrice(int position);
    Item* BuyItem(int position);
    float SellItem(Item* item);
    float GetPriceItem(int position);
    void PrintSellingItems();
};


class ShopPlace: public IPlace
{
public:
    ShopPlace(IMap* map, Shop* shop);

    Shop* shop;
    std::vector<int> PrintRoutes();
    //  Place virtual methods
    void EnterPlace(IPlayer* player);
    void PromptInput();
    void ReadInput();
    void ExitPlace();
};