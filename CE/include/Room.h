#pragma once
#include <list>
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

    RoomLevel(int level, int points, int updateCost);
    
};

class Room
{
public:
    RoomType roomType;
    int currLevel;
    std::list<RoomLevel> roomLevels;

    Room();
    
    Room(RoomType roomType, int currLevel, std::list<RoomLevel> roomLevels);
};
