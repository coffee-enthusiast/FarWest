#pragma once

#include "Home.h"
#include "../../UF/include/EntitiesInterfaces.h"
#include "Skill.h"
#include "Item.h"
#include "../../UF/include/ActionAttributes.h"
#include <vector>

enum AttributeTag
{
    MONEY,
    HP, //  Health Points
    SP,  //  Stamina Points
};

class Inventory
{
public:
    std::vector<Item*> items;
    int maxItems;
    Inventory();
    Inventory(std::vector<Item*> items, int maxItems);
    bool AddItem(Item* item);
    void DeleteItem(int pos);
    int GetFreeCapacity();
    int GetCapacity();
    std::string PrintInventory();
};

class Player : public IPlayer
{
public:

    int maxHealth;
    int maxStamina;
    int numberOfGuns;
    float playerAttributes[3];
    bool alive;
    PlayerAction playerAction;
    Skill miningSkill;
    Skill shootingSkill;
    Home playerHome;
    Inventory playerInventory;

    Player();

    void printStats();

    void addHealth(int healthAmount);
    int getHealth();

    void addStamina(int staminaAmount);


    void goToSleep();

    void Consume(Item item);
    //  IPlayer methods
    void    simulateAction();    
    int     getPlayerAction();
    void     setPlayerAction(int action);
    bool    isPlayerAlive();
    void    setPlayerAlive(bool alive);
    int     getNumberOfGuns();
    int     getShootingSkillLevel();
    void    useSkill(SkillTag skill);
};