#ifndef LOCATION
#define LOCATION

#include <string>
#include <vector>
#include "Character.h"

class Location {
private:
    std::string name; 
    std::vector<Character*> entities; 

public:
    Location(std::string name);  
    void addEntity(Character* entity);  
    void removeEntity(Character* entity);  
    void interactWithEntities(Character* player); 
    void displayLocation() const;  
    std::string getName() const; 
};

#endif

