#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <string>

#include "MovementSystem.h"
#include "NumberGenerator.h"

struct Entity{
    int _x, _y = 0;

    virtual void Act(std::vector<std::string>&) = 0;

    MovementSystem _moveSystem;

    virtual ~Entity() = default;
};

struct Player : public Entity {
    char sym = 'P';
    int _x = 1; int _y =1;

    void Act(std::vector<std::string>&) {};
    
};

struct Zombie : public Entity {
    //move in a direction until 
    char sym = 'z';

    int moveSpeed = 1;
    int stepCounter = 0;
    int moveDirection = NumberGenerator::getIntRanged(3);

    void Act(std::vector<std::string>& levelMap) { 
        Wonder( levelMap );
    }

    void Wonder(std::vector<std::string>& levelMap){ 
        bool bContinueDirection;

        if (NumberGenerator::getIntRanged(1) > 0){
            switch (moveDirection)
            {
            case 0:
                bContinueDirection = _moveSystem.move(_x, _y, _x, _y + 1, levelMap, sym);
                break;
            case 1:
                bContinueDirection = _moveSystem.move(_x, _y, _x, _y - 1, levelMap, sym);
                break;
            case 2:
                bContinueDirection = _moveSystem.move(_x, _y, _x + 1, _y, levelMap, sym);
                break;
            case 3:
                bContinueDirection = _moveSystem.move(_x, _y, _x - 1, _y, levelMap, sym);
                break;
            default:
                break;
            }
        }
       
        if (stepCounter++ >= 4){
           moveDirection = NumberGenerator::getIntRanged(3);
        }
    }
};



#endif