#ifndef COMPATABLE
#define COMPATABLE
#include <iostream>
#include <string>
#include "Character.h"
#include "Interactable.h"


class NPC:public Character, public Interactable
{
    private:
        std::string message;
    public:
    NPC(std::string name, int health, int attackPower, int defense, std::string message);
    void speak() const;
    void interact() override ;
    void displayStats() const override;

};
#endif