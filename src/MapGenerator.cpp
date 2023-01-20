#include "MapGenerator.h"

//Use Data in LevelChunks dir to form level in columns-
//start with left column initialising number of rows-
//add to initialise rows with middle and right column call

std::vector<std::string> MapGenerator::generateMap(){
    generateLeftColumn();
    generateMiddleColumn();
    generateMiddleColumn();
    generateRightColumn();

    return _generatedMap;
}

//return a path to a randomly chosen level chunk from dir

std::string MapGenerator::selectLevelTile(std::string pathToTiles){

    std::string selectedTilePath;

    std::vector<std::string> tilePaths;

    for (const auto & value : std::filesystem::directory_iterator(pathToTiles)){
        tilePaths.push_back(value.path());
    }
    
    int randomIndex = _numberGenerator.getIntRanged((tilePaths.size() - 1)); 

    return tilePaths[randomIndex];
}

//load in chosen level chunk with getLine()-
//feed level data into _generatedMap vector-
//change folder path to level data with the Switch and for loop.

void MapGenerator::generateLeftColumn(){
    std::ifstream fileInput;
    std::string input;
    
    for (size_t i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            fileInput.open(selectLevelTile(_topLeftPath));
            if (fileInput.fail()){
                std::cerr << "top left path failiure" << std::endl;
            }
            break;

        case 1:
            fileInput.open(selectLevelTile(_middleLeftPath));
            if (fileInput.fail()){ 
                std::cerr << "middle left path failed to open" << std::endl;
            }
            break;

        case 2:
            fileInput.open(selectLevelTile(_bottomLeftPath));
            if (fileInput.fail()){ 
                std::cerr << "bottom left path failed to open" << std::endl;
            }
            break;
            
        default:
            std::cout << "error opening filePath" << std::endl;
            break;
        }

        while(getline(fileInput, input)){
            _generatedMap.push_back(input);
        }

        fileInput.close();
    }
}

void MapGenerator::generateMiddleColumn(){
    std::ifstream fileInput;
    int index = 0;
    std::string input;

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            fileInput.open(selectLevelTile(_topMiddlePath));
            if (fileInput.fail()){ 
                std::cerr << "Top Middle Path failed to open" << std::endl;
            }
            break;
        case 1:
            fileInput.open(selectLevelTile(_middleMiddlePath));
            if (fileInput.fail()){ 
                std::cerr << "Middle middle Path failed to open" << std::endl;
            }
            break;
        case 2:
            fileInput.open(selectLevelTile(_middleBottomPath));
            if (fileInput.fail()){ 
                std::cerr << "Middle Bottom Path failed to open" << std::endl;
            }
            break;
        
        default:
            std::cerr << "middle column map generation switch out of range" << std::endl;
            break;
        }

        while(getline(fileInput, input)){
            _generatedMap[index] += input;
            index ++;
        }

        fileInput.close();
    }
}

void MapGenerator::generateRightColumn(){
    std::ifstream fileInput;
    int index = 0;
    std::string input;

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            fileInput.open(selectLevelTile(_topRightPath));
            if (fileInput.fail()){ 
                std::cerr << "Top Right Path failed to open" << std::endl;
            }
            break;
        case 1:
            fileInput.open(selectLevelTile(_middleRightPath));
            if (fileInput.fail()){ 
                std::cerr << "Middle Right Path failed to open" << std::endl;
            }
            break;
        case 2:
            fileInput.open(selectLevelTile(_bottomRightPath));
            if (fileInput.fail()){ 
                std::cerr << "bottom Right Path failed to open" << std::endl;
            }
            break;
        
        default:
            std::cerr << "Right column map generation switch out of range" << std::endl;
            break;
        }

        while(getline(fileInput, input)){
            _generatedMap[index] += input;
            index ++;
        }

        fileInput.close();
    }
}

void MapGenerator::displayMap(){
    for (int i = 0; i < _generatedMap.size(); i++)
        {
            std::cout << _generatedMap[i] << std::endl;
        }
}