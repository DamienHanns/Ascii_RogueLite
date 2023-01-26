#include "GameMaster.h"

//setout map 
//find spawn positions and spawn in entities at those positions
//_zobies.at() and related setup code used for placement as push_back() caused
// inconsistant - Memory Segmentaion Fault - Not sure why.
void GameMaster::setupGame(){
    system("clear");

    _levelMap = _mapGenerator.generateMap();

    MapConstituents mapConstituents;

    //spawn treasures
    int totalTreasures =  NumberGenerator::getIntRanged(3, 1);
    _treasures.resize(totalTreasures);

    for (int i = 0; i < totalTreasures; i++)
    {
        Treasure t;
        
        int maxXPos = mapConstituents.chunkSizeX * mapConstituents.coloums;
        int maxYPos = mapConstituents.chunkSizeY * mapConstituents.rows;
        
        bool bHasSpawnPosition = false;
        
        while (bHasSpawnPosition == false)
        {
            t._x = NumberGenerator::getIntRanged(maxXPos, mapConstituents.chunkSizeX);
            t._y = NumberGenerator::getIntRanged(maxYPos, mapConstituents.chunkSizeY); 
            
            bHasSpawnPosition = _moveSystem.testMapPosition(t._x, t._y, _levelMap);
        }

        _treasures.at(i) = t;

        placeEntitesOnMap();
    } 

    //spawn zombies
    int totalZombies =  NumberGenerator::getIntRanged(30, 20);
    _zombies.resize(totalZombies);

    for (int i = 0; i < totalZombies; i++)
    {
        Zombie z;
        
        int maxXPos = mapConstituents.chunkSizeX * mapConstituents.coloums;
        int maxYPos = mapConstituents.chunkSizeY * mapConstituents.rows;
        
        bool bHasSpawnPosition = false;
        
        while (bHasSpawnPosition == false)
        {
            z._x = NumberGenerator::getIntRanged(maxXPos, mapConstituents.chunkSizeX);
            z._y = NumberGenerator::getIntRanged(maxYPos, mapConstituents.chunkSizeY); 
            
            bHasSpawnPosition = _moveSystem.testMapPosition(z._x, z._y, _levelMap);
        }

        _zombies.at(i) = z;

        placeEntitesOnMap();

    } 

    //clear and populate map again to get rid of erroneous entities at pos (0,0)
    _levelMap = _mapGenerator.getGeneratedMap();
    placeEntitesOnMap();
    displayLevel();
}

//place entities on level map starting with _player
void GameMaster::placeEntitesOnMap(){
    std::string& playerY = _levelMap[_player._y];
    playerY [_player._x] = _player._sym;

   for(Treasure& t : _treasures){
       std::string& treasureYPos = _levelMap[t._y];
       treasureYPos [t._x] = t._sym;
    }

    for(Zombie& z : _zombies){
       std::string& zombieYPos = _levelMap[z._y];
       zombieYPos [z._x] = z._sym;
    }
}

void GameMaster::runGame(){
    _gameRunning = true;

    while (_gameRunning)
    {
        processPlayerInput();
        updateEntities();
        displayLevel();
        displayInformation();
    }
}

void GameMaster::processPlayerInput(){
    std::string input;
    std::cin >> input;

    bool positionFree;

    for (int i = 0; i < 3; i++)
    {
        char playerInput = input[i];
        switch (playerInput)
        {
        case 'x':
            _gameRunning = false;
            break;
        case 'w':
            positionFree =_moveSystem.move(_player._x, _player._y, _player._x, _player._y - 1, _levelMap, _player._sym);
            if (!positionFree) { 
                attemptTreasurePickup(getMapSymbol(_player._x, _player._y - 1, _levelMap), _player._x, _player._y - 1, _levelMap); 
            }
            break;
        case 's':
            positionFree = _moveSystem.move(_player._x, _player._y, _player._x, _player._y + 1, _levelMap, _player._sym);
            if (!positionFree) { 
                attemptTreasurePickup(getMapSymbol(_player._x, _player._y + 1, _levelMap), _player._x, _player._y + 1, _levelMap); 
            }
            break;
        case 'a':
            positionFree = _moveSystem.move(_player._x, _player._y, _player._x - 1, _player._y, _levelMap, _player._sym);
             if (!positionFree) { 
                attemptTreasurePickup(getMapSymbol(_player._x - 1, _player._y, _levelMap), _player._x - 1, _player._y, _levelMap); 
            }
            break;
        case 'd':
            positionFree = _moveSystem.move(_player._x, _player._y, _player._x + 1, _player._y, _levelMap, _player._sym);
            if (!positionFree) { 
                attemptTreasurePickup(getMapSymbol(_player._x + 1, _player._y, _levelMap), _player._x + 1, _player._y, _levelMap); 
            }
        default:
            break;
        }
    }
}

//check for treasure symbol at map locaiton player is trying to move to.
void GameMaster::attemptTreasurePickup(char foundEntity, int desiredPosX, int desiredPosY, std::vector<std::string>& levelMap){
    if (foundEntity == 'T') {
        _moveSystem.forceMove(_player._x, _player._y, desiredPosX , desiredPosY, levelMap, _player._sym);
    }
}

char GameMaster::getMapSymbol(int xPos, int yPos, std::vector<std::string>& levelMap){
    std::string& value = levelMap[yPos];
    return value [xPos];
}

//pass _levelMap into act() for AI functions
//also check for game neding states.
void GameMaster::updateEntities(){
    for(Zombie& z : _zombies){
        z.act(_levelMap);
    }

    for (Treasure& t : _treasures){
        _gameNotWon = _moveSystem.testMapPosition(t._x, t._y, _levelMap, t._sym);
        if (_gameNotWon == true) break;
    }

    _playerAlive = _moveSystem.testMapPosition(_player._x, _player._y, _levelMap, _player._sym);
    if (!_playerAlive) {_gameRunning = false;}

    if (_gameNotWon == false) {_gameRunning = false;}
}

void GameMaster::displayLevel(){
    system("clear");
    for (size_t i = 0; i < _levelMap.size(); i++)
    {
        std::cout << _levelMap[i] << std::endl;
    }
}

//lets the player know what to expect next turn.
void GameMaster::displayInformation(){
    if (_gameRunning){
        std::cout << "You can move 3 positions per turn." << "\n";
        std::cout << "Plan your movement with w,a,s,d - then press Enter " << "\n";
        std::cout << "To quit input x - then press Enter" << std::endl;
    }
    else {
        if (_gameNotWon == false) {   
            std::cout << " - - - Well done you won - - -" << std::endl;
            std::cout << " - - Thank you for playing - -" << std::endl;
            return;
        }
        if (_playerAlive) {
            std::cout << " - - Thank you for playing - -" << std::endl;
        }
        else {
            std::cout << " - - - -  Game Over  - - - -" << std::endl;
            std::cout << " A Zombie got you. Bad luck." << std::endl;
            std::cout << " - - - -  Game Over  - - - -" << std::endl;
        }
    }
}
