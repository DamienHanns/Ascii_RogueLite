#include <iostream>
#include <string>
#include "LevelGenerator.h"
#include "NumberGenerator.h"


int main(){

    std::string inputForSeed;

    std::cout << "A new hero arrives." << std::endl;
    std::cout << "What is your name?" << std::endl;

    std::cin >> inputForSeed;

    NumberGenerator numGenerator(inputForSeed);
    LevelGenerator levelGen;

    levelGen.GenerateLevel();
    levelGen.DisplayLevel();
    

    return 0;
}
