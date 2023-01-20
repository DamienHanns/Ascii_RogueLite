#include <iostream>
#include <string>
#include <filesystem>

#include "MapGenerator.h"
#include "NumberGenerator.h"
#include "GameMaster.h"


int main(){
    //setup game
    std::string _inputForSeed;

    std::cout << "A new hero arrives." << std::endl;
    std::cout << "What is your name?" << std::endl;

    std::cin >> _inputForSeed;

    NumberGenerator _numberGenerator (_inputForSeed);
    MapGenerator _mapGenerator (_numberGenerator);

    GameMaster gM(_numberGenerator, _mapGenerator);

    gM.setupGame();

    gM.runGame();

    //run game
    

    return 0;
}
