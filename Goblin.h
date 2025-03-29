#ifndef GOBLIN
#define GOBLIN

#include "Character.h"  

class Goblin : public Character {
private:
    int a;  
public:
    Goblin(std::string name, int health, int attackPower, int defense, int a)
        : Character(name, health, attackPower, defense), a(a) {}

    void displayStats() const override {
        std::cout << "Goblin - " << getname() << std::endl;
        std::cout << "Health: " << gethealth() << " | Attack: " << getattackpow() << " | Defense: " << getdefense() << std::endl;
    }

    int getLootValue() const {
        return a;
    }

    void takeDamage(int damage) override {
        int reducedDamage = damage - getdefense();
        if (reducedDamage < 0) reducedDamage = 0;  
        Character::takeDamage(reducedDamage);
    }
};

#endif
