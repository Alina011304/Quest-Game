#include "Character.h"


Character::Character(std::string name, int health, int attackPower, int defense): name(name), health(health), attackPower(attackPower), defense(defense) {}

Character::~Character() noexcept {}

void Character::takeDamage(int damage) {
    int damageTaken = damage - defense;
    if (damageTaken > 0) {
        health -= damageTaken;
        std::cout << name << " takes " << damageTaken << " damage!" << std::endl;
    } else {
        std::cout << name << " blocked the damage!" << std::endl;
    }
}

std::string Character::getname() const {
    return name;
}

int Character::gethealth() const {
    return health;
}

int Character::getattackpow() const {
    return attackPower;
}

int Character::getdefense() const {
    return defense;
}

void Character::setHealth(int newHealth) {
    health = newHealth;
}
