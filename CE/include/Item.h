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
};

enum ItemSubCategory
{
    //  HEAL
    FOOD,
    DRINK,
    //  GUN
    PRIMARY_GUN,
    SECONDARY_GUN,
    //  AMMO
    REVOLVER_AMMO,
    RIFFLE_AMMO,
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