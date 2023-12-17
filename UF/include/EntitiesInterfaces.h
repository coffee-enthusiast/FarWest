#pragma once
#include "Tags.h"
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
    virtual int     getDamage()  = 0;
    virtual void    useSkill(SkillTag skill) = 0;
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
    virtual void ChangePlace(int nextPlace) = 0;
};

class IPlace
{
public:
    IMap* map;
    PlaceTag placeTag;
    virtual void EnterPlace() = 0;
    virtual void PromptInput() = 0;
    virtual void ReadInput() = 0;
    virtual void ExitPlace() = 0;
};

