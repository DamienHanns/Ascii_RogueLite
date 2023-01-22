#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <vector>
#include <string>

#include "MapGenerator.h"
#include "NumberGenerator.h"
#include "Entity.h"


class GameMaster{

private:
    bool _gameRunning;

    NumberGenerator& _numberGenerator;
    MapGenerator& _mapGenerator;

    Player _player;

    std::vector <Zombie> _zombies;
    std::vector <std::string> _levelMap;

    void processInput();
    void updateEntities();
    void displayLevel();
    void displayInstructions();

    void placeEntitesOnMap();
    bool testMapPosition(int xPos, int yPos);

    bool move(int& startingX, int& startingY, int desiredXPos, int desiredYPos);

public:

    void setupGame();
    void runGame();

    GameMaster(NumberGenerator& numberGenerator, MapGenerator& mapGenerator);
};



#endif

