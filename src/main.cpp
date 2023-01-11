#include <iostream>
#include <string>
#include <filesystem>

#include "MapGenerator.h"
#include "NumberGenerator.h"


int main(){
    std::string _inputForSeed;

    std::cout << "A new hero arrives." << std::endl;
    std::cout << "What is your name?" << std::endl;

    std::cin >> _inputForSeed;

    NumberGenerator _numberGenerator(_inputForSeed);
    MapGenerator _levelGen(_numberGenerator);

    _levelGen.generateLevel();
    _levelGen.displayLevel();
    

    return 0;
}
