#include "Hero.h"
#include <iostream>

Hero::Hero(std::string name, int health, int attackPower, int defense): Character(name, health, attackPower, defense), XP(0), level(1), currentMount(nullptr) {}

void Hero::attack(Character& target) {
    int damage = getattackpow() - target.getdefense();
    target.takeDamage(damage);
    std::cout << getname() << " attacks " << target.getname() << " for " << damage << " damage!\n";
}

void Hero::takeDamage(int amount) {
    int damageTaken = amount - getdefense();
    if (damageTaken > 0) {
        setHealth(gethealth() - damageTaken);
        std::cout << getname() << " takes " << damageTaken << " damage!" << std::endl;
    } else {
        std::cout << getname() << " blocked the attack!" << std::endl;
    }
}


void Hero::gainXP(int amount) {
    XP += amount;
    std::cout << getname() << " gains " << amount << " XP!" << std::endl;
    
    if (XP >= 100) 
    { 
        levelUp();
    }
}
void Hero::levelUp() {
    level++;
    XP = 0;  
    std::cout << getname() << " leveled up to level " << level << "!" << std::endl;
}

int Hero::getXP() const {
    return XP;
}

int Hero::getLevel() const {
    return level;
}

void Hero::displayStats() const {
    std::cout << "Hero Stats: " << std::endl;
    std::cout << "Name: " << getname() << "\nHealth: " << gethealth()
              << "\nAttack: " << getattackpow() << "\nDefense: " << getdefense()
              << "\nXP: " << XP << "\nLevel: " << level << std::endl;
}
void Hero::interact() {
    std::cout << "Hero interacts with the environment." << std::endl;
}