#include "../../UF/include/EntitiesInterfaces.h"
#include "../include/Map.h"


class GameEngine
{
public:
    int currDay;
    Map map;
    GameEngine();
    int simulateDay(IPlayer* p);
    int gunFight(IPlayer* p);
};