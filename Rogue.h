#ifndef ROGUE
#define ROGUE

#include "Hero.h"
#include <iostream>

class Rogue : public Hero {
private:
    int dexterity; 

public:
    Rogue(std::string name) : Hero(name, 90, 18, 6), dexterity(20) {}
    void attack(Character& target) override {
        std::cout << getname() << " strikes quickly and silently at " << target.getname() << "!" << std::endl;
        target.takeDamage(getattackpow() + 5);  
    }
};
#endif