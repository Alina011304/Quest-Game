#ifndef MONSTER
#define MONSTER
#include "Character.h"
#include "Compatable.h"  

class Monster : public Character, public Combatable {
private:
    std::string tesak; 
public:
    Monster(std::string name, int health, int attackPower, int defense, std::string tesak);
    void attack(Character& target) override;
};

#endif  