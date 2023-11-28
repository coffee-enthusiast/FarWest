#include "Room.h"

RoomLevel::RoomLevel(int level, int points, int updateCost)
{
    this->level = level;
    this->points = points;
    this->updateCost = updateCost;
}

Room::Room()
{

}

Room::Room(RoomType roomType, int currLevel, std::list<RoomLevel> roomLevels)
{
    this->roomType = roomType;
    this->currLevel = currLevel;
    this->roomLevels = roomLevels;
}