
#include "../../UF/include/EntitiesInterfaces.h"



class GameEngine
{
public:
    int currDay;
    GameEngine();
    int simulateDay(IPlayer* p);
    int gunFight(IPlayer* p);
};