#pragma once

#include "Home.h"
enum PlayerAction
{
    WORK,
    DRINK,
    EAT,
    BUY_GUN,
    SLEEP,
    EXIT
};

class Player
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

    Home playerHome;

    Player();

    void printStats();

    void addHealth(int healthAmount);

    void addStamina(int staminaAmount);

    void simulateAction();    

    void goToSleep();
};