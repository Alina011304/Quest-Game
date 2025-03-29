#ifndef MAGE
#define MAGE

#include "Hero.h"
#include <iostream>

class Mage : public Hero {
public:
    Mage(const std::string& name) : Hero(name, 100, 30, 5) {}

    void displayStats() const override {
        std::cout << "Mage: " << getname() << "\n"
                  << "Health: " << gethealth() << "\n"
                  << "Attack Power: " << getattackpow() << "\n"
                  << "Defense: " << getdefense() << "\n";
    }

    void takeDamage(int amount) override {
        int damageTaken = amount - getdefense();
        if (damageTaken < 0) damageTaken = 0;

        setHealth(gethealth() - damageTaken);
        std::cout << getname() << " takes " << damageTaken << " damage!\n";
    }

    void attack(Character& target) override {
        std::cout << getname() << " casts a powerful spell at " << target.getname() << "!\n";
        target.takeDamage(getattackpow());
    }
};

#endif
