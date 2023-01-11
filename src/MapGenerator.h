#ifndef MapGENERATOR_H
#define MapGENERATOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
#include "NumberGenerator.h"

class MapGenerator
{
private:
    // tile directory locations
    std::string _topLeftPath = "./LevelChunks/Left/Top";
    std::string _middleLeftPath = "./LevelChunks/Left/Middle";
    std::string _bottomLeftPath = "./LevelChunks/Left/Bottom";

    std::string _topMiddlePath = "./LevelChunks/Middle/Top";
    std::string _middleMiddlePath = "./LevelChunks/Middle/Middle";
    std::string _middleBottomPath =  "./LevelChunks/Middle/Bottom";

    std::string _topRightPath = "./LevelChunks/Right/Top";
    std::string _middleRightPath = "./LevelChunks/Right/Middle";
    std::string _bottomRightPath = "./LevelChunks/Right/Bottom";
    
    std::vector <std::string> _generatedMap; 

    void generateLeftColumn();
    void generateMiddleColumn();
    void generateRightColumn();

    std::string selectLevelTile(std::string pathToTiles);

    NumberGenerator& _numberGenerator;

public:
    void generateLevel();
    void displayLevel();

    MapGenerator(NumberGenerator& numberGenerator) : _numberGenerator (numberGenerator){};
};


#endif