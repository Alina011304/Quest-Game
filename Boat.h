#ifndef BOAT
#define BOAT
#include "Mount.h"

class Boat : public Mount {
private:
    std::string waterType; 

public:
    Boat(std::string name, int speed, std::string waterType) : Mount(name, speed), waterType(waterType) {}

    void move() const override {
        std::cout << "name"<< mountName << " speed " << speed << " watertype " << waterType << "." << std::endl;
    }

    void dock() const {
        std::cout << "The boat " << mountName << " docks safely." << std::endl;
    }
};
#endif
