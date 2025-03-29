#ifndef WEAPON
#define WEAPON
#include "Item.h"
#include "Character.h"

class Weapon : public Item {
private:
    int attackPower;  

public:

    Weapon(std::string name, std::string description, int value, int attackPower): Item(name, description, value), attackPower(attackPower) {}

    int getAttackPower() const 
    {
        return attackPower;
    }

    void use() override 
    {
        std::cout << "You equip the " << itemName << " and prepare for battle." << std::endl;
    }
    ~Weapon() override = default;
};

#endif
