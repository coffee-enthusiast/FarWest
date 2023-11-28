#include "Player.h"

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
    std::cout << "=============" << std::endl;
    std::cout << "Player Stats:" << std::endl;
    std::cout << "=============" << std::endl;
    std::cout    << "\tMoney: $" << money << std::endl
            << "\tHealth: " << health << "/" << maxHealth << std::endl
            << "\tStamina: " << stamina << "/" << maxStamina << std::endl
            << "\tNo of guns: " << numberOfGuns << std::endl;
    std::cout << "--------------------------" << std::endl;
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
                    std::cout << "Not enough stamina to work!" << std::endl;
                    break;
                }
                if(health < abs(workHealth))
                {
                    std::cout << "Not enough health to work!" << std::endl;
                    break;
                }
                std::cout << "Went for work!" << std::endl;
                addHealth(workHealth);
                addStamina(workStamina);
                money += workMoney;
                break;
            case DRINK:
                if(money < drinkCost)
                {
                    std::cout << "Not enough money to buy drink!" << std::endl;
                    break;
                }
                std::cout << "Got a drink!" << std::endl;
                money -= drinkCost;
                addStamina(drinkStamina);
                break;
            case EAT:
                if(money < foodCost)
                {
                    std::cout << "Not enough money to buy food!" << std::endl;
                    break;
                }
                std::cout << "Ate food!" << std::endl;
                money -= foodCost;
                addHealth(foodHealth);
                addStamina(foodStamina);
                break;
            case BUY_GUN:
                if(money < gunCost)
                {
                    std::cout << "Not enough money to buy gun!" << std::endl;
                    break;
                }
                std::cout << "Bought a gun!" << std::endl;
                money -= gunCost;
                numberOfGuns++;
                break;
            case SLEEP:
                std::cout << "Went for sleep!" << std::endl;
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