#ifndef HERO
#define HERO
#include "Character.h"
#include "Compatable.h"
#include "Interactable.h"
#include "Item.h"
#include "Mount.h"
#include <vector>

class Hero : public Character, public Combatable, public Interactable
{
private:
    int XP;            
    int level;          
    std::vector<Item*> inventory; 
    Mount* currentMount; 

public:
    Hero(std::string name, int health, int attackPower, int defense);


    void attack(Character& target) override;
    void takeDamage(int amount) override;
    void interact() override;

    void gainXP(int amount); 

  
    void levelUp(); 

    int getXP() const;     
    int getLevel() const;    
    void displayStats() const override; 
};

#endif
