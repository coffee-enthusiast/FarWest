// PlayerFactory.h (Example)
#pragma once
#include "EntitiesInterfaces.h"
#include "../../CE/include/Player.h" // Include the concrete implementation

class PlayerFactory {
public:
    static IPlayer* createPlayer() {
        return new Player(); // Return an instance of the concrete class
    }
};