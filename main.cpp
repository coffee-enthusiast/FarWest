#include <iostream>
#include <cstdlib>
#include <time.h>  
#include <list>
using namespace std;

int drinkCost   = 1;
int drinkStamina = 2;

int foodCost   = 2;
int foodHealth = 2;
int foodStamina = 2;

int sleepHealth = 1;
int sleepStamina = 3;

int workHealth  = -1;
int workStamina = -2;
int workMoney   = 2;

int gunCost = 5;
int currDay = 1;

int playerInput = 0;


enum RoomType
{
    BEDROOM,
    KITCHEN
};

class RoomLevel
{
public:
    int level;
    int points;

    int updateCost;

    RoomLevel(int level, int points, int updateCost)
    {
        this->level = level;
        this->points = points;
        this->updateCost = updateCost;
    }
};

class Room
{
public:
    RoomType roomType;
    int currLevel;
    list<RoomLevel> roomLevels;

    Room()
    {

    }
    
    Room(RoomType roomType, int currLevel, list<RoomLevel> roomLevels)
    {
        this->roomType = roomType;
        this->currLevel = currLevel;
        this->roomLevels = roomLevels;
    }
};

class Home
{
    int safetyLevel;
    int maxGuns;
    Room bedroom;
    Room kitchen;
    // Updates costs
    int safetyUpdateCost;
    int maxGunsUpdateCost;
public:
    Home()
    {
        safetyLevel = 0;
        maxGuns     = 0;

        safetyUpdateCost    = 3;
        maxGunsUpdateCost   = 4;

        bedroom = Room(BEDROOM, 1, list<RoomLevel>());
        kitchen = Room(KITCHEN, 1, list<RoomLevel>());

    }
};

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

    Player()
    {
        money       = 5;
        health      = 10;
        maxHealth   = 10;
        stamina     = 5;
        maxStamina  = 5;
        numberOfGuns = 0;
        alive      = true;
    }

    void printStats()
    {
        cout << "=============" << endl;
        cout << "Player Stats:" << endl;
        cout << "=============" << endl;
        cout    << "\tMoney: $" << money << endl
                << "\tHealth: " << health << "/" << maxHealth << endl
                << "\tStamina: " << stamina << "/" << maxStamina << endl
                << "\tNo of guns: " << numberOfGuns << endl;
        cout << "--------------------------" << endl;
    }

    void addHealth(int healthAmount)
    {
        health += healthAmount;
        if(health > maxHealth)
            health = maxHealth;
        if(health < 0)
            health = 0;
    }

    void addStamina(int staminaAmount)
    {
        stamina += staminaAmount;
        if(stamina > maxStamina)
            stamina = maxStamina;
        if(stamina < 0)
            stamina = 0;
    }

    void simulateAction()
    {
        switch(playerAction)
        {
            case WORK:
                if(stamina < abs(workStamina))
                {
                    cout << "Not enough stamina to work!" << endl;
                    break;
                }
                if(health < abs(workHealth))
                {
                    cout << "Not enough health to work!" << endl;
                    break;
                }
                cout << "Went for work!" << endl;
                addHealth(workHealth);
                addStamina(workStamina);
                money += workMoney;
                break;
            case DRINK:
                if(money < drinkCost)
                {
                    cout << "Not enough money to buy drink!" << endl;
                    break;
                }
                cout << "Got a drink!" << endl;
                money -= drinkCost;
                addStamina(drinkStamina);
                break;
            case EAT:
                if(money < foodCost)
                {
                    cout << "Not enough money to buy food!" << endl;
                    break;
                }
                cout << "Ate food!" << endl;
                money -= foodCost;
                addHealth(foodHealth);
                addStamina(foodStamina);
                break;
            case BUY_GUN:
                if(money < gunCost)
                {
                    cout << "Not enough money to buy gun!" << endl;
                    break;
                }
                cout << "Bought a gun!" << endl;
                money -= gunCost;
                numberOfGuns++;
                break;
            case SLEEP:
                cout << "Went for sleep!" << endl;
                goToSleep();
                break;
            default:
                break;
        }
    }

    void goToSleep()
    {
        addHealth(sleepHealth);
        addStamina(sleepStamina);
    }
};




void prompt()
{
    cout << "Press 1: Work\t\t(+$2,\t" << workStamina << " Stamina,\t" << workHealth << " Health)"<< endl
        << "Press 2: Drink Cola\t(+2 Stamina, -$1)" << endl
        << "Press 3: Eat Beans\t(+2 Stamina, +2 Health, -$2)" << endl
        << "Press 4: Buy Gun\t(+1 Gun,\t-$5)" << endl
        << "Press 5: Sleep\t\t(+" << sleepStamina <<" Stamina,\t+"<<sleepHealth<<" Health)" << endl
        << "Press 6: Exit" << endl;
        
    cout << "-----------------------------------------------------" << endl;
}

int readInput()
{
    cin >> playerInput;
    return playerInput;
}

void processInput(Player* p)
{
    switch(playerInput)
    {
        case 1:
            p->playerAction = WORK;
            break;
        case 2:
            p->playerAction = DRINK;
            break;
        case 3:
            p->playerAction = EAT;
            break;
        case 4:
            p->playerAction = BUY_GUN;
            break;
        case 5:
            p->playerAction = SLEEP;
            break;
        case 6:
            p->playerAction = EXIT;
            break;
        default:
            break;
    }
}
    


int simulateDay(Player* p)
{
    srand(time(0));
    int chance = rand() % 10;

    // Bad luck
    if(chance <= 3)
    {
        cout << "!Bad luck!" << endl;
        if(p->numberOfGuns == 0)
        {
            cout << "You died!" << endl;
            p->alive = false;
        }
        else
        {
            p->numberOfGuns--;
        }
        return 1;
    }
    return 0;
}

int main()
{ 
    Player player = Player();
    cout << "Welcome cowboy!" << endl;

    while(player.playerAction != EXIT && player.alive == true)
    {
        cout << "Day: " << currDay++ << endl;
        player.printStats();
        prompt();
        for(int i = 0; i < 3; i++)
        {
            cout << "Action(" << (i+1) << "/3):" << endl;
            readInput();
            processInput(&player);
            player.simulateAction();
            player.printStats();
            if(player.playerAction == SLEEP)
                break;
        }
        simulateDay(&player);
        player.goToSleep();
    }

    return 0;
}