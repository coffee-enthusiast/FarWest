// PlayerFactory.h (Example)
#pragma once
#include "EntitiesInterfaces.h"
#include "../../CE/include/Player.h" // Include the concrete implementation
#include "../../CE/include/Home.h" // Include the concrete implementation
#include "../../CE/include/Shop.h" // Include the concrete implementation

class PlayerFactory {
public:
    static IPlayer* createPlayer() {
        return new Player(); // Return an instance of the concrete class
    }
};

class HomeFactory {
public:
    static IPlace* createHome(IMap *map) {
        return new HomePlace(map); // Return an instance of the concrete class
    }
};

class ShopFactory {
public:
    static IPlace* createShop(IMap *map) {
        return new ShopPlace(map); // Return an instance of the concrete class
    }
};