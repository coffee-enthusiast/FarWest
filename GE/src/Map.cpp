#include "../include/Map.h"

Map::Map()
{
    routes = new std::vector<int>[3];

    routes[HOME].push_back(SHOP);
    routes[HOME].push_back(MINE);

    routes[SHOP].push_back(HOME);

    routes[MINE].push_back(HOME);
    routes[MINE].push_back(SHOP);

    places[HOME] = new Place(this);
    places[SHOP] = new Place(this);
    places[MINE] = new Place(this);

}

void Map::ChangePlace(int place)
{
    currentPlace->ExitPlace();

    currentPlace = places[place];

    currentPlace->EnterPlace();
}

