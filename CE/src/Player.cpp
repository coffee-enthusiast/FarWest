#include "Player.h"
#include "../../UI/include/IOFunctions.h"
#include "../../UI/include/Trace.h"
#include "../../UF/include/ActionAttributes.h"
#include <iostream>
#include <time.h>
#include <string>

#include "Shop.h"
Inventory::Inventory()
{
    this->maxItems = 5;
}

Inventory::Inventory(std::vector<Item*> items, int maxItems)
{
    this->items = items;
    this->maxItems = maxItems;
}

bool Inventory::AddItem(Item* item)
{
    if(items.size() == maxItems)
        return false;

    items.push_back(item);
    return true;
}

void Inventory::DeleteItem(int pos)
{
    if(items.size() == 0 || pos >= items.size())
        return;
    
    items.erase(items.begin() + pos);
}

int Inventory::GetFreeCapacity()
{
    return (maxItems - items.size());
}

int Inventory::GetCapacity()
{
    return maxItems;
}

std::string Inventory::PrintInventory()
{
    std::string str;
    for(int i = 0; i < maxItems; i++)
    {

        str += std::to_string(i) + "| ";
        if(i >= items.size())
        {
            str += " _\n";
            continue;
        }

        str += items[i]->itemName + "\t" + std::to_string((ItemType)items[i]->itemType) + " ";

        for(std::pair<int,int> gain : items[i]->gains)
        {
            str += std::to_string(gain.second) + " " + std::to_string((AttributeTag)gain.first);
        }
        str += "\n";
    }

    return str;
}

Player::Player()
{
    maxHealth   = 10;
    maxStamina  = 5;
    numberOfGuns = 0;
    alive      = true;
    playerAttributes[MONEY] = 5;
    playerAttributes[HP] = 10;
    playerAttributes[SP] = 5;
    playerInventory = Inventory();

    miningSkill = Skill(std::string("Mining"),2,30,100,10);
    shootingSkill = Skill(std::string("Shooting"),5,80,100,10);
}

void Player::printStats()
{
    
    fOut("=============");
    fOut("Player Stats:");
    fOut("=============");
    fOut("\tMoney: $" + std::to_string(playerAttributes[MONEY]));
    fOut("\tHealth: " + std::to_string(playerAttributes[HP]) + "/" + std::to_string(maxHealth));
    fOut("\tStamina: " + std::to_string(playerAttributes[SP]) + "/" + std::to_string(maxStamina));
    fOut("\tNo of guns: " + std::to_string(numberOfGuns));
    fOut("=============");

    fOut("Player Inventory:");
    fOut("=============");
    fOut(playerInventory.PrintInventory());
    fOut("--------------------------");
}

void Player::addHealth(int healthAmount)
{
    playerAttributes[HP] += healthAmount;
    if(playerAttributes[HP] > maxHealth)
        playerAttributes[HP] = maxHealth;
    if(playerAttributes[HP] < 0)
        playerAttributes[HP] = 0;
}

int Player::getHealth()
{
    return playerAttributes[HP];
}

void Player::addStamina(int staminaAmount)
{
    playerAttributes[SP] += staminaAmount;
    if(playerAttributes[SP] > maxStamina)
        playerAttributes[SP] = maxStamina;
    if(playerAttributes[SP] < 0)
        playerAttributes[SP] = 0;
}

void Player::simulateAction()
{
    int mineChance;
    switch(playerAction)
    {
        case (PlayerAction)WORK:
            if(playerAttributes[SP] < abs(workStamina))
            {
                fOutWarn("Not enough stamina to work!");
                break;
            }
            if(playerAttributes[HP] < abs(workHealth))
            {
                fOutWarn("Not enough health to work!");
                break;
            }
            fOut("Went for work!");
            addHealth(workHealth);
            addStamina(workStamina);
            srand(time(0));
            mineChance = rand() % 10;
            int amount;
            if(mineChance <= miningSkill.skillLevel)
            {
                amount = workMoney;
            }
            else
            {
                amount = workMoney / 2;
            }
            playerAttributes[MONEY] += amount;
            fOutWarn("\t" + std::to_string(workHealth) + " HP");
            fOutWarn("\t" + std::to_string(workStamina) + " St.");
            fOutSucc("\t+ " + std::to_string(amount) + "$");
            break;
        case (PlayerAction)DRINK:
        {
            if(playerInventory.GetFreeCapacity() < 1)
            {
                fOutWarn("Not enough inventory capacity to buy drink!");
                break;
            }
            Shop s = Shop();
            Item* drink = s.BuyItem(0, &playerAttributes[MONEY]);
            if(drink == nullptr)
            {
                fOutWarn("Not enough money to buy drink!");
                break;
            }

            playerInventory.AddItem(drink);

            fOut("Got a drink!");
            fOutWarn("\t- " + std::to_string(s.GetPriceItem(0)) + "$");
            break;
        }
        case (PlayerAction)EAT:
        {
            if(playerInventory.GetFreeCapacity() < 1)
            {
                fOutWarn("Not enough inventory capacity to buy food!");
                break;
            }

            Shop s = Shop();
            Item* beans = s.BuyItem(1, &playerAttributes[MONEY]);
            if(beans == nullptr)
            {
                fOutWarn("Not enough money to buy food!");
                break;
            }
            playerInventory.AddItem(beans);

            fOut("Ate food!");
            fOutWarn("\t- " + std::to_string(s.GetPriceItem(1)) + "$");
            break;
        }
        case (PlayerAction)BUY_GUN:
            if(playerAttributes[MONEY] < gunCost)
            {
                fOutWarn("Not enough money to buy gun!");
                break;
            }
            fOut("Bought a gun!");
            playerAttributes[MONEY] -= gunCost;
            numberOfGuns++;
            fOutWarn("\t -" + std::to_string(gunCost) + "$");
            fOutSucc("\t +1 Gun");
            break;
        case (PlayerAction)SLEEP:
            fOut("Went for sleep!");
            goToSleep();
            break;
        case (PlayerAction)ACCESS_INVENTORY:
            if(playerInventory.GetCapacity() == 0)
                break;
            Consume(*playerInventory.items[0]);
        default:
            break;
    }
}

void Player::Consume(Item item)
{
    if(item.itemType != CONSUMABLE)
        return;
    for(std::pair<int,int> p : item.gains)
    {
        switch((AttributeTag)p.first)
        {
            case MONEY:
                playerAttributes[MONEY] += p.second;
                break;
            case HP:
                addHealth(p.second);
                break;
            case SP:
                addStamina(p.second);
                break;
            default:
                break;
        }
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
    playerAction = (PlayerAction) (action-1);
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

int Player::getShootingSkillLevel()
{
    return shootingSkill.skillLevel;
}

void Player::useSkill(SkillTag skill)
{
    switch (skill)
    {
    case SHOOTING:
        shootingSkill.trainSkill(20);
        break;
    case MINING:
        miningSkill.trainSkill(15);
        break;
    default:
        break;
    }
}