#include <iostream>
#include <string>
#include <filesystem>

#include "MapGenerator.h"
#include "NumberGenerator.h"
#include "GameMaster.h"

void introMessage();

int main(){
    system("clear");

    introMessage();

    std::string _inputForSeed;
    std::cin >> _inputForSeed;

    NumberGenerator _numberGenerator (_inputForSeed);

    GameMaster gM;

    gM.setupGame();

    gM.runGame();

    return 0;
}

void introMessage(){
    std::cout << "###########################" << std::endl;
    std::cout << "# WELCOME TREASURE HUNTER #" << std::endl;
    std::cout << "###########################" << std::endl;
    std::cout << "\n";
    std::cout << "###########################" << std::endl;
    std::cout << "#       P = Player        #" << std::endl;
    std::cout << "#       z = Zombie        #" << std::endl;
    std::cout << "#       T = Treasure      #" << std::endl;
    std::cout << "###########################" << std::endl;
    std::cout << "\n";
    std::cout << "Rules" << std::endl;
    std::cout <<"_______" << std::endl;
    std::cout << "1. Collect all of the treasure." << std::endl;
    std::cout << "2. Your movements will be executed exactly as they are input." << std::endl;
    std::cout << "3. Don't get eaten." << std::endl;
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Give over your name, and we'll get going." << std::endl;
    std::cout << "Name: ";
}