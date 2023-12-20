#pragma once
#include <string>
#include <vector>
#include "../../UF/include/EntitiesInterfaces.h"
enum ItemType
{
    CONSUMABLE, //  HEAL
    USABLE, //  GUN, AMMO
    WEARABLE,
};

enum ItemCategory
{
    HEAL,
    GUN,
    AMMO,
    ROCK,
};

enum ItemSubCategory
{
    //  HEAL
    FOOD = 0,
    DRINK,
    //  GUN
    PRIMARY_GUN = 2,
    SECONDARY_GUN,
    //  AMMO
    REVOLVER_AMMO = 4,
    RIFFLE_AMMO,
    //  ROCKS
    GOLD = 6,
    DIAMONT,
    SIMPLE_ROCK,
};

class Item
{
public:
    std::string itemName;
    ItemType itemType;
    ItemCategory itemCategory;
    ItemSubCategory itemSubCategory;
    std::vector<std::pair<int,int>> gains;

    Item(std::string itemName, ItemType itemType, ItemCategory itemCategory, ItemSubCategory itemSubCategory, std::vector<std::pair<int,int>> gains);
};

class Gun : public Item
{
public:
    float gunDamage;

};