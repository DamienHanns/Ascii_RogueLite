#include "GameMaster.h"

//setout map 
//find spawn positions and spawn in entities at those positions
void GameMaster::setupGame(){
    system("clear");
    
    _levelMap = _mapGenerator.generateMap();

    MapConstituents mapConstituents;

    //spawn zombies
    for (int i = 0; i < _numberGenerator.getIntRanged(30, 20); i++)
    {
        Zombie z;
        
        int maxXPos = mapConstituents.chunkSizeX * mapConstituents.coloums;
        int maxYPos = mapConstituents.chunkSizeY * mapConstituents.rows;
        
        bool bHasSpawnPosition = false;
        
        while (bHasSpawnPosition == false)
        {
            z._x = _numberGenerator.getIntRanged(maxXPos, mapConstituents.chunkSizeX);
            z._y = _numberGenerator.getIntRanged(maxYPos, mapConstituents.chunkSizeY); 
            
            bHasSpawnPosition = testMapPosition(z._x, z._y);
        }
        
        _zombies.push_back(z);

        placeEntitesOnMap();
    }

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
            move(_player._x, _player._y, _player._x, _player._y - 1);
            break;
        case 's':
            move(_player._x, _player._y, _player._x, _player._y + 1);
            break;
        case 'a':
            move(_player._x, _player._y, _player._x - 1, _player._y);
            break;
        case 'd':
            move(_player._x, _player._y, _player._x + 1, _player._y);
        default:
            break;
        }
    }
}

void GameMaster::updateEntities(){
    system("clear");
    _levelMap = _mapGenerator.getGeneratedMap();

    //call Act on entities.

    placeEntitesOnMap();
}

bool GameMaster::move(int& posX, int& posY,  int desiredXPos, int desiredYPos){
    
    if ( testMapPosition(desiredXPos, desiredYPos) ){ 
        posX = desiredXPos;
        posY = desiredYPos;
        return true;
    }
    else return false;
}

//after all positions have been updated place entites on map
//start with _player then place other entities
void GameMaster::placeEntitesOnMap(){
    std::string& playerY = _levelMap[_player._y];
    playerY [_player._x] = _player.sym;

    for(Zombie& z : _zombies){
       std::string& zombieYPos = _levelMap[z._y];
       zombieYPos [z._x] = z.sym;
    }
}

bool GameMaster::testMapPosition(int xPos, int yPos){

    bool bPositionAvailible;
    char mapSymbol;

    std::string& value = _levelMap[yPos];
    mapSymbol = value [xPos];
    
    mapSymbol == '.' ? bPositionAvailible = true : bPositionAvailible = false;

    return bPositionAvailible;
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