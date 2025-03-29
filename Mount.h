#ifndef MOUNT
#define MOUNT
#include <iostream>
#include <string>

class Mount {
protected:
    std::string mountName;
    int speed; 

public:
    Mount(std::string name, int speed) : mountName(name), speed(speed) {}

    virtual void move() const {
        std::cout << "name" << mountName << " speed" << speed <<  std::endl;
    }

    virtual ~Mount() = default;
};
#endif
