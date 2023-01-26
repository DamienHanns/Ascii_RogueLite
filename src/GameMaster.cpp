#include "GameMaster.h"

//setout map 
//find spawn positions and spawn in entities at those positions
//_zobies.at() and related setup code used for placement as push_back() caused
// inconsistant - Memory Segmentaion Fault - Not sure why.
void GameMaster::setupGame(){
    system("clear");

    _levelMap = _mapGenerator.generateMap();

    MapConstituents mapConstituents;

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

    //clear and populate map again to get rid of entity at pos (0,0)
    _levelMap = _mapGenerator.getGeneratedMap();
    placeEntitesOnMap();
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
            _moveSystem.move(_player._x, _player._y, _player._x, _player._y - 1, _levelMap, _player.sym);
            break;
        case 's':
            _moveSystem.move(_player._x, _player._y, _player._x, _player._y + 1, _levelMap, _player.sym);
            break;
        case 'a':
            _moveSystem.move(_player._x, _player._y, _player._x - 1, _player._y, _levelMap, _player.sym);
            break;
        case 'd':
            _moveSystem.move(_player._x, _player._y, _player._x + 1, _player._y, _levelMap, _player.sym);
        default:
            break;
        }
    }
}

//pass _levelMap into Act() for AI functions
void GameMaster::updateEntities(){
    system("clear");

    for(Zombie& z : _zombies){
        z.Act(_levelMap);
    }
}

//place entities on level map starting with _player
void GameMaster::placeEntitesOnMap(){
    std::string& playerY = _levelMap[_player._y];
    playerY [_player._x] = _player.sym;

    for(Zombie& z : _zombies){
       std::string& zombieYPos = _levelMap[z._y];
       zombieYPos [z._x] = z.sym;
    }
}

void GameMaster::displayLevel(){
    for (size_t i = 0; i < _levelMap.size(); i++)
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
