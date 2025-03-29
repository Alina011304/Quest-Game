#ifndef REPUTATION
#define REPUTATION
#include <iostream>

class Reputation {
private:
    int points; 

public:
    Reputation() : points(0) {}

    void increaseReputation(int amount) {
        points += amount;
        std::cout << "Reputation increased by " << amount << ". Current reputation: " << points << std::endl;
    }

    void decreaseReputation(int amount) {
        points -= amount;
        std::cout << "Reputation decreased by " << amount << ". Current reputation: " << points << std::endl;
    }

    int getReputation() const {
        return points;
    }
};
#endif
