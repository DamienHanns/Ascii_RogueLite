#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <vector>
#include <string>

#include "MapGenerator.h"
#include "NumberGenerator.h"


class GameMaster{

struct Position{
    int x, y;
    int getX() { return x;} int getY() { return y;}
};

struct Player {
    Position position;
    char sym = 'P';
} _player;

private:
    bool _gameRunning;

    NumberGenerator& _numberGenerator;
    MapGenerator& _mapGenerator;

    std::vector <std::string> _levelMap;

    void processInput();
    void updateEntities();
    void displayLevel();
    void displayInstructions();

    void placeEntites();

    void moveOrCollide(Position& startingPosition, int desiredXPos, int desiredYPos);

public:

    void setupGame();
    void runGame();

    GameMaster(NumberGenerator& numberGenerator, MapGenerator& mapGenerator);
};



#endif

