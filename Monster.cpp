#include "Monster.h"
#include <iostream>

Monster::Monster(std::string name, int health, int attackPower, int defense, std::string tesak): Character(name, health, attackPower, defense), tesak(tesak) {}

void Monster::attack(Character& target) {
    std::cout << getname() << " attacks with " << tesak << "!\n";
    
    int damage = getattackpow() - target.getdefense();
    if (damage < 0) {
        damage = 0;  
    }
    target.takeDamage(damage);
}
