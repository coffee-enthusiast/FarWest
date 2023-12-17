#include "../include/Map.h"

Map::Map()
{
    routes = new std::vector<int>[3];

    routes[HOME].push_back(SHOP);
    routes[HOME].push_back(MINE);

    routes[SHOP].push_back(HOME);

    routes[MINE].push_back(HOME);
    routes[MINE].push_back(SHOP);


}
void Map::SetPlaces(std::vector<IPlace*> places)
{
    this->places = places;

    currentPlace = nullptr;

}

void Map::ChangePlace(int place)
{
    if(currentPlace != nullptr)
        currentPlace->ExitPlace();

    currentPlace = places[place];

    currentPlace->EnterPlace();
}

