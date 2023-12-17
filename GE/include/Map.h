#include <vector>

enum PlaceTag
{
    HOME,
    SHOP,
    MINE,
};

class Place
{
public:
    Place(Map* map);
    Map* map;
    PlaceTag placeTag;
    virtual void EnterPlace();
    virtual void PromptInput();
    virtual void ReadInput();
    virtual void ExitPlace();
};

class Map
{
public:
    std::vector<int>* routes;
    Place* places[3];
    Map();
    Place* currentPlace;
    void ChangePlace(int nextPlace);
};