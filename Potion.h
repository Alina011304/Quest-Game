#ifndef POTION
#define POTION
#include "Item.h"
#include "Character.h"

class Potion : public Item {
private:
    int healingAmount;  
public:
    
    Potion(std::string name, std::string description, int value, int healingAmount) : Item(name, description, value), healingAmount(healingAmount) {}

    int getHealingAmount() const {
        return healingAmount;
    }
    void use() override {
        std::cout << "You drink the " << itemName << " and recover " << healingAmount << " health!" << std::endl;
    }

    ~Potion() override = default;
};

#endif
