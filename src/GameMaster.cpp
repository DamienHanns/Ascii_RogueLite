#include "GameMaster.h"

void GameMaster::setupGame(){
    _player.position.x = _player.position.y = 1;
    _levelMap = _mapGenerator.generateMap();
    updateEntities();
    displayLevel();  
}

void GameMaster::runGame(){
    _gameRunning = true;

    while (_gameRunning)
    {
        processInput();
        updateEntities();
        displayLevel();
    }
}

void GameMaster::processInput(){
    std::string input;
    std::cin >> input;

    for (int i = 0; i < 3; i++)
    {
        char playerInput = input[i];
        switch (playerInput)
        {
        case 'x':
            _gameRunning = false;
            break;
        case 'w':
            moveOrCollide(_player.position, _player.position.x, _player.position.getY() - 1);
            //_player._posY --;
            break;
        case 's':
            moveOrCollide(_player.position, _player.position.x, _player.position.getY() + 1);
            //_player._posY ++;
            break;
        case 'a':
            moveOrCollide(_player.position, _player.position.getX() - 1, _player.position.getY());
            //_player._posX --;
            break;
        case 'd':
            moveOrCollide(_player.position, _player.position.getX() + 1, _player.position.getY());
            //_player._posX ++;
        default:
            break;
        }
    }
}

void GameMaster::updateEntities(){
    system("clear");
    _levelMap = _mapGenerator.getGeneratedMap();

    placeEntites();
}

//check the symbol at the desired position in the level. 
//If the symbol is a '.' update entity postion.
void GameMaster::moveOrCollide(Position& entityPosition, int desiredXPos, int desiredYPos){
    char levelSymbol;

    std::string& value = _levelMap[desiredYPos];
    levelSymbol = value[desiredXPos];

    if (levelSymbol == '.'){ 
        entityPosition.x = desiredXPos;
        entityPosition.y = desiredYPos;
    }
}

//after all positions have been updated place entites on map
//start with _player then place other entities
void GameMaster::placeEntites(){
    std::string& value = _levelMap[_player.position.getY()];
    value [_player.position.getX()] = _player.sym;
}

void GameMaster::displayLevel(){
    for (int i = 0; i < _levelMap.size(); i++)
    {
        std::cout << _levelMap[i] << std::endl;
    }

    displayInstructions();
}

void GameMaster::displayInstructions(){
    std::cout << "You can move 3 positions per turn." << "\n";
    std::cout << "Plan your movement with w,a,s,d - then press Enter " << "\n";
    std::cout << "To quit input x - then press Enter" << std::endl;
}

GameMaster::GameMaster(NumberGenerator& numberGenerator, MapGenerator& mapGenerator) : 
    _numberGenerator(numberGenerator), _mapGenerator(mapGenerator)   {};