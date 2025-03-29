#include "GameWorld.h"
#include "Location.h"
#include "NPC.h"
#include "Monster.h"
#include <iostream>

GameWorld::GameWorld(Character* player) : player(player) {}

GameWorld::~GameWorld() {
    cleanUp();
}

void GameWorld::cleanUp() {
    for (size_t i = 0; i < locations.size(); ++i) { 
        delete locations[i];  
    }
    locations.clear(); 
}

void GameWorld::addLocation(Location* location) {
    locations.push_back(location);
}

void GameWorld::movePlayerTo(Location* newLocation) {
    std::cout << "Moving player to: " << newLocation->getName() << std::endl;
    newLocation->displayLocation();  
    newLocation->interactWithEntities(player); 
}

void GameWorld::encounter() {
    for (size_t i = 0; i < locations.size(); ++i) { 
        locations[i]->interactWithEntities(player);  
    }
}
void GameWorld::displayWorld() const {
    std::cout << "Game World State:\n";
    std::cout << "Player: " << player->getname() << " - Health: " << player->gethealth() << std::endl;
    std::cout << "Locations in the world:\n";

    for (size_t i = 0; i < locations.size(); ++i) {  
        locations[i]->displayLocation(); 
    }
}
