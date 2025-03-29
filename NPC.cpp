#include "NPC.h"
#include "Character.h"


NPC::NPC(std::string name, int health, int attackPower, int defense, std::string message)
    : Character(name, health, attackPower, defense), message(message) {}

void NPC::speak() const {
    std::cout << getname() << " message " << message << std::endl;
}

void NPC::interact() {
    speak(); 
    std::cout << "You have interacted with " << getname() << "!" << std::endl;
}

void NPC::displayStats() const {
    std::cout << "name " << getname() << " message " << message<< " health" << gethealth()
              << " attack" << getattackpow() << " defense " << getdefense() << std::endl;
}