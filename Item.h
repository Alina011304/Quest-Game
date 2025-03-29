#ifndef ITEM
#define ITEM
#include <string>
#include <iostream>

class Item {
protected:
    std::string itemName;
    std::string itemDescription;
    int itemValue;

public:
    Item(std::string name, std::string description, int value): itemName(name), itemDescription(description), itemValue(value) {}

    std::string getName() const 
    {
        return itemName;
    }

    std::string getDescription() const 
    {
        return itemDescription;
    }

    int getValue() const
    {
        return itemValue;
    }

    virtual void use() = 0;
    virtual ~Item() = default;
};

#endif
