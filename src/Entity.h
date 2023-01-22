#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

class Entity{
public:
    int _x, _y = 0;
    virtual void Act() = 0;

    Entity(/* args */) {};
    virtual ~Entity(/* args */) {};
};

struct Player : public Entity {
    void Act() {};
    int _x = 1; int _y =1;
    char sym = 'P';
};

struct Zombie : public Entity {
    void Act() { std::cout << "act is being overridden" << std::endl;}
    char sym = 'z';
};


#endif