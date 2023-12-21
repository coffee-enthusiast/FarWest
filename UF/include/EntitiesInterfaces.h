#pragma once
#include <vector>
#include "Tags.h"
#include "../../CE/include/Item.h"
class Item;

class IPlayer
{
public:

    virtual int     getPlayerAction()   = 0;
    virtual void    setPlayerAction(int action)   = 0;
    virtual bool    isPlayerAlive()     = 0;
    virtual void    setPlayerAlive(bool alive)     = 0;
    virtual void    printStats()        = 0;
    virtual void    simulateAction()    = 0;
    virtual void    goToSleep()         = 0;
    virtual int     getNumberOfGuns()   = 0;
    virtual void    addHealth(int healthAmount)         = 0;
    virtual int     getHealth()         = 0;
    virtual int     getShootingDamage()  = 0;
    virtual int     getMiningDamage()  = 0;
    virtual void    addMoney(float moneyAmount) = 0;
    virtual float   totalMoney() = 0;
    virtual void    useSkill(SkillTag skill) = 0;
    virtual void    addItem(Item* item) = 0;
    virtual void    printItemsInventory()        = 0;
    virtual Item*   getItemFromInventory(int position) = 0;
    virtual void   discardItemFromInventory(int position) = 0;
};

class IEntity
{
public:
    
};

class IInteractable
{
public:
    virtual void Interact() = 0;
};

class IConsumable
{
public:
    virtual void Consume() = 0;
};

class IMap
{
public:
    IPlayer *player;
    virtual std::vector<int> GetRoutes(int fromPlace) = 0;
    virtual void ChangePlace(int nextPlace) = 0;
};

class IPlace
{
public:
    IMap* map;
    IPlayer* player;
    PlaceTag placeTag;
    virtual void EnterPlace(IPlayer* player) = 0;
    virtual void PromptInput() = 0;
    virtual void ReadInput() = 0;
    virtual void ExitPlace() = 0;
};

