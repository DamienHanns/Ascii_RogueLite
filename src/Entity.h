#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <string>

#include "MovementSystem.h"
#include "NumberGenerator.h"


struct Entity{
    int _x, _y = 0;

    char _sym = 0;
    
    virtual ~Entity() = default;
};

struct Treasure : public Entity
{
    char _sym = 'T';
};


struct Player : public Entity {
    char _sym = 'P';
    int _x = 1; int _y =1;
};

//move in a direction 4 units or untill an obsticle is encountered
//if an obsticle is encountered try and bite it.
struct Zombie : public Entity {

    char _sym = 'z';

    MovementSystem _moveSystem;
    
    int _stepCounter = 0;
    int _moveDirection = NumberGenerator::getIntRanged(3);

    void act(std::vector<std::string>& levelMap) { 
        wonder(levelMap);
    }

    bool wonder(std::vector<std::string>& levelMap){ 
        bool positionFree = true;

        if (NumberGenerator::getIntRanged(4) > 0){
            switch (_moveDirection)
            {
            case 0:
                positionFree = _moveSystem.move(_x, _y, _x, _y + 1, levelMap, _sym);
                if (!positionFree) { 
                    biteEntity( getMapSymbol(_x, _y + 1, levelMap), _x, _y + 1, levelMap); 
                }
                break;
            case 1:
                positionFree = _moveSystem.move(_x, _y, _x, _y - 1, levelMap, _sym);
                if (!positionFree) { 
                    biteEntity( getMapSymbol(_x, _y - 1, levelMap), _x, _y - 1, levelMap);  
                }
                break;
            case 2:
                positionFree = _moveSystem.move(_x, _y, _x + 1, _y, levelMap, _sym);
                if (!positionFree) { 
                     biteEntity( getMapSymbol(_x + 1, _y, levelMap), _x + 1, _y, levelMap); 
                }
                break;
            case 3:
                positionFree = _moveSystem.move(_x, _y, _x - 1, _y, levelMap, _sym);
                if (!positionFree) { 
                    biteEntity( getMapSymbol(_x - 1, _y, levelMap), _x - 1, _y, levelMap); 
                }
                break;
            default:
                break;
            }
        }
       
        if (_stepCounter++ >= 4 || positionFree == false){
           _moveDirection = NumberGenerator::getIntRanged(3);
        }

        return positionFree;
    }

    void biteEntity(char foundEntity, int desiredPosX, int desiredPosY, std::vector<std::string>& levelMap){
        if (foundEntity == 'P') {
            _moveSystem.forceMove(_x, _y, desiredPosX , desiredPosY, levelMap, _sym);
            
        }
    }

    char getMapSymbol(int xPos, int yPos, std::vector<std::string>& levelMap){
    std::string& value = levelMap[yPos];
    return value [xPos];
    }
};

#endif