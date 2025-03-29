#ifndef WARRIOR_H
#define WARRIOR_H

#include "Hero.h"

class Warrior : public Hero {
public:
    Warrior(const std::string& name) : Hero(name, 120, 20, 10) {} 

    void displayStats() const override {
        std::cout << "Warrior: " << getname() << "\n"
                  << "Health: " << gethealth() << "\n"
                  << "Attack Power: " << getattackpow() << "\n"
                  << "Defense: " << getdefense() << "\n";
    }


    void takeDamage(int amount) override {
        int damageTaken = amount - getdefense();
        if (damageTaken < 0) damageTaken = 0;  
        setHealth(gethealth() - damageTaken);  
        std::cout << getname() << " takes " << damageTaken << " damage, remaining health: " << gethealth() << std::endl;
    }

    void interact() override {
        std::cout << getname()<< std::endl;
    }
};

#endif
