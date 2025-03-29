#ifndef INTERACTABLE
#define INTERACTABLE

class Interactable {
public:
    virtual void interact() = 0; 
    virtual ~Interactable() = default;
};

#endif
