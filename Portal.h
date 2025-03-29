#ifndef PORTAL
#define PORTAL
#include <iostream>
#include "Character.h"
#include "Location.h"

class Portal {
private:
    std::string portalName;
    Location* destination;  

public:
    
    Portal(std::string name, Location* destination)
        : portalName(name), destination(destination) {}

   
    void use(Character* character) {
        std::cout << character->getname() << " entered the portal and arrived at " 
                  << destination->getName() << "!" << std::endl;
        std::cout << "For now, no direct change in character's location." << std::endl;
    }
    std::string getPortalName() const {
        return portalName;
    }
};

#endif
