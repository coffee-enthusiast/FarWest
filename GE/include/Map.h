#pragma once
#include <vector>
#include "../../UF/include/EntitiesInterfaces.h"

class Map : public IMap
{
public:
    std::vector<int>* routes;
    std::vector<IPlace*> places;
    IPlace* currentPlace;

    Map();

    void SetPlaces(std::vector<IPlace*> places);
    void ChangePlace(int nextPlace);
};





