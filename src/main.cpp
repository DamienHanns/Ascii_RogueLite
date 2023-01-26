#include <iostream>
#include <string>
#include <filesystem>

#include "MapGenerator.h"
#include "NumberGenerator.h"
#include "GameMaster.h"

int main(){
    system("clear");

    std::cout << "A new hero arrives." << std::endl;
    std::cout << "What is your name?" << std::endl;

    std::string _inputForSeed;
    std::cin >> _inputForSeed;

    NumberGenerator _numberGenerator (_inputForSeed);

    GameMaster gM;

    gM.setupGame();

    gM.runGame();

    return 0;
}