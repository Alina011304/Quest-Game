#ifndef COMBATABLE
#define COMBATABLE_
#include "Character.h"

class Combatable 
{
    public:
        virtual void attack(Character& taget) = 0;  
        virtual void takeDamage(int damage) = 0;
        virtual ~Combatable() = default;
};

#endif
