#include "Location.h"
#include <iostream>

Location::Location(std::string name) : name(name) {}

void Location::addEntity(Character* entity) 
{
    entities.push_back(entity);
}

void Location::removeEntity(Character* entity) 
{
    for (size_t i = 0; i < entities.size(); ++i) 
    {
        if (entities[i] == entity) {
            entities.erase(entities.begin() + i);
            break;
        }
    }
}
void Location::interactWithEntities(Character* player) 
{
    for (Character* entity : entities) {
        entity->takeDamage(10); 
        std::cout << player->getname() << " interacts with " << entity->getname() << std::endl;
    }
}

void Location::displayLocation() const
{
    std::cout << "Location: " << name << std::endl;
    std::cout << "Entities in this location:" << std::endl;
    for (const Character* entity : entities) {
        std::cout << entity->getname() << " (Health: " << entity->gethealth() << ")" << std::endl;
    }
}

std::string Location::getName() const
 {
    return name;
}
