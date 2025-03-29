#ifndef GAMEWORLD
#define GAMEWORLD

#include <vector>
#include "Location.h"
#include "Character.h"

class GameWorld {
private:
    std::vector<Location*> locations; 


    void cleanUp();

public:
    Character* player;
    GameWorld(Character* player);
    ~GameWorld();
    void addLocation(Location* location);
    void movePlayerTo(Location* newLocation);
    void encounter();
    void displayWorld() const;
};

#endif 
