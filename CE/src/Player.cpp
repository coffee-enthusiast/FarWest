#include "Player.h"
#include "../../UI/include/IOFunctions.h"
#include "../../UF/include/ActionAttributes.h"
#include <iostream>
Player::Player()
{
    money       = 5;
    health      = 10;
    maxHealth   = 10;
    stamina     = 5;
    maxStamina  = 5;
    numberOfGuns = 0;
    alive      = true;
}

void Player::printStats()
{
    
    fOut("=============");
    fOut("Player Stats:");
    fOut("=============");
    fOut("\tMoney: $" + std::to_string(money));
    fOut("\tHealth: $" + std::to_string(health) + "/" + std::to_string(maxHealth));
    fOut("\tStamina: $" + std::to_string(stamina) + "/" + std::to_string(maxStamina));
    fOut("\tNo of guns: " + std::to_string(numberOfGuns));
    fOut("--------------------------");
}

void Player::addHealth(int healthAmount)
{
    health += healthAmount;
    if(health > maxHealth)
        health = maxHealth;
    if(health < 0)
        health = 0;
}

int Player::getHealth()
{
    return health;
}

void Player::addStamina(int staminaAmount)
{
    stamina += staminaAmount;
    if(stamina > maxStamina)
        stamina = maxStamina;
    if(stamina < 0)
        stamina = 0;
}

void Player::simulateAction()
    {
        switch(playerAction)
        {
            case WORK:
                if(stamina < abs(workStamina))
                {
                    fOutWarn("Not enough stamina to work!");
                    break;
                }
                if(health < abs(workHealth))
                {
                    fOutWarn("Not enough health to work!");
                    break;
                }
                fOut("Went for work!");
                addHealth(workHealth);
                addStamina(workStamina);
                money += workMoney;
                break;
            case DRINK:
                if(money < drinkCost)
                {
                    fOutWarn("Not enough money to buy drink!");
                    break;
                }
                fOut("Got a drink!");
                money -= drinkCost;
                addStamina(drinkStamina);
                break;
            case EAT:
                if(money < foodCost)
                {
                    fOutWarn("Not enough money to buy food!");
                    break;
                }
                fOut("Ate food!");
                money -= foodCost;
                addHealth(foodHealth);
                addStamina(foodStamina);
                break;
            case BUY_GUN:
                if(money < gunCost)
                {
                    fOutWarn("Not enough money to buy gun!");
                    break;
                }
                fOut("Bought a gun!");
                money -= gunCost;
                numberOfGuns++;
                break;
            case SLEEP:
                fOut("Went for sleep!");
                goToSleep();
                break;
            default:
                break;
        }
    }

    void Player::goToSleep()
    {
        addHealth(sleepHealth);
        addStamina(sleepStamina);
    }

    int Player::getPlayerAction()
    {
        return (int)playerAction;
    }
    void Player::setPlayerAction(int action)
    {
        playerAction = (PlayerAction) action;
    }

    bool Player::isPlayerAlive()
    {
        return alive;
    }
    void Player::setPlayerAlive(bool alive)
    {
        this->alive = alive;
    }
    int Player::getNumberOfGuns()
    {
        return numberOfGuns;
    }