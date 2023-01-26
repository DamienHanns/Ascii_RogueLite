#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include <string>
#include <vector>

class MovementSystem
{
private:
    /* data */
public:

    bool move(int& posX, int& posY,  int desiredXPos, int desiredYPos, std::vector<std::string>& levelMap, char entitySym){
    
        if ( testMapPosition(desiredXPos, desiredYPos, levelMap) ){ 
            
            std::string& mapStartingPos = levelMap[posY];
            mapStartingPos [posX] = '.';

            posX = desiredXPos;
            posY = desiredYPos;

            std::string& entityEndPos = levelMap[posY];
            entityEndPos [posX] = entitySym;
            
            return true;
        }
        else return false;
    }

    bool testMapPosition(int xPos, int yPos, std::vector<std::string>& levelMap){

        bool bPositionAvailible;
        char mapSymbol;

        std::string& value = levelMap[yPos];
        mapSymbol = value [xPos];
        
        mapSymbol == '.' ? bPositionAvailible = true : bPositionAvailible = false;

        return bPositionAvailible;
    }


    MovementSystem(/* args */){};
};


#endif