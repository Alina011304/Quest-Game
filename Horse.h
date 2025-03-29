#ifndef HORSE
#define HORSE
#include "Mount.h"

class Horse : public Mount {
public:
    Horse(std::string name, int speed) : Mount(name, speed) {}

    void move() const override {
        std::cout << "The horse " << mountName << " gallops at a speed of " << speed << " units." << std::endl;
    }

    void jump() const {
        std::cout << "The horse " << mountName << " jumps over an obstacle!" << std::endl;
    }
};
#endif
