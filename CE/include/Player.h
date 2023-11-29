#pragma once

#include "Home.h"
#include "../../UF/include/EntitiesInterfaces.h"
#include "Skill.h"
enum PlayerAction
{
    WORK,
    DRINK,
    EAT,
    BUY_GUN,
    SLEEP,
    EXIT
};

class Player : public IPlayer
{
public:

    int money;
    int health;
    int maxHealth;
    int stamina;
    int maxStamina;
    int numberOfGuns;
    bool alive;
    PlayerAction playerAction;
    Skill skill1;
    Skill skill2;
    Home playerHome;

    Player();

    void printStats();

    void addHealth(int healthAmount);
    int getHealth();

    void addStamina(int staminaAmount);

    void simulateAction();    

    void goToSleep();

    //  IPlayer methods
    int     getPlayerAction();
    void     setPlayerAction(int action);
    bool    isPlayerAlive();
    void    setPlayerAlive(bool alive);
    int     getNumberOfGuns();
};