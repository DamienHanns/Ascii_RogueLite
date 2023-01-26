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
    bool _gameNotWon = true;

    MapGenerator _mapGenerator;
    MovementSystem _moveSystem;

    Player _player;
    bool _playerAlive;

    std::vector <Treasure> _treasures;
    std::vector <Zombie> _zombies;
    std::vector <std::string> _levelMap;
    std::vector <std::string> _levelMapPreviousTurn; 


    void processPlayerInput();
    void updateEntities();
    void displayLevel();
    void displayInformation();

    void placeEntitesOnMap();

    void attemptTreasurePickup(char foundEntity, int desiredPosX, int desiredPosY, std::vector<std::string>& levelMap);
    char getMapSymbol(int xPos, int yPos, std::vector<std::string>& levelMap);

public:
    void setupGame();
    void runGame();

    GameMaster() {} ;
};

#endif