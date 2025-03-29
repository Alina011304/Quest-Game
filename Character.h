#ifndef CHARACTER
#define CHARACTER
#include <iostream>
#include <string>
class Character
{
    private:
        std::string name;
        int health;
        int attackPower;
        int defense;

    public:

        Character(std::string name, int health, int attackPower,int defense);
        virtual void displayStats() const = 0;
        virtual void takeDamage(int damage);

        virtual ~Character()  noexcept;
        std::string getname()const;
        int gethealth()const;
        int getattackpow()const;
        int getdefense()const;
        void setHealth(int newHealth);

};

#endif

