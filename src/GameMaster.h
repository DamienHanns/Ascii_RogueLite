#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <vector>
#include <string>
#include <memory>

#include "MapGenerator.h"
#include "NumberGenerator.h"
#include "Entity.h"
#include "MovementSystem.h"

class GameMaster{

private:
    bool _gameRunning;

    MapGenerator _mapGenerator;
    MovementSystem _moveSystem;

    Player _player;

    std::vector <Zombie> _zombies;
    std::vector <std::string> _levelMap;
    std::vector <std::string> _levelMapPreviousTurn; 


    void processInput();
    void updateEntities();
    void displayLevel();
    void displayInstructions();

    void placeEntitesOnMap();

public:
    void setupGame();
    void runGame();

    GameMaster() {} ;
};




#endif

