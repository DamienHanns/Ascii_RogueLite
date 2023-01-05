#ifndef LEVELGENERATOR_H
#define LEVELGENERATOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


class LevelGenerator
{
private:
    std::string topLeftPath = {"./LevelChunks/Left/topLeft.chunk"};
    std::string middleLeftPath = {"./LevelChunks/Left/middleLeft.chunk"};
    std::string bottomLeftPath = {"./LevelChunks/Left/bottomLeft.chunk"};

    std::string topMiddlePath = {"./LevelChunks/Middle/middleTop.chunk"};
    std::string middleMiddlePath = {"./LevelChunks/Middle/middleMid.chunk"};
    std::string middleBottomPath =  {"./LevelChunks/Middle/middleBottom.chunk"};

    std::string topRightPath = "./LevelChunks/Right/topRight.chunk";
    std::string middleRightPath = "./LevelChunks/Right/middleRight.chunk";
    std::string bottomRightPath = "./LevelChunks/Right/bottomRight.chunk";
    
    std::vector <std::string> generatedLevel;

    void GenerateLeftColumn();
    void GenerateMiddleColumn();
    void GenerateRightColumn();


public:
    void GenerateLevel();
    void DisplayLevel();

    LevelGenerator(/* args */);
};




#endif