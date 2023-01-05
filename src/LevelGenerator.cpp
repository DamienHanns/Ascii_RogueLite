#include "LevelGenerator.h"

LevelGenerator::LevelGenerator(/* args */)
{
}

//Get tile data from files in LevelChunks dir- Use Data to form level in columns- 
//start with left column to initalise number of rows for the level- 
//add to existing rows with middle and right column calls.

void LevelGenerator::GenerateLevel(){
    GenerateLeftColumn();
    GenerateMiddleColumn();
    GenerateMiddleColumn();
    GenerateRightColumn();
}

void LevelGenerator::GenerateLeftColumn(){
    std::ifstream fileInput;
    std::string input;
    
    for (size_t i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            fileInput.open(topLeftPath);
            if (fileInput.fail()){ 
                std::cerr << "top left path failed to open" << std::endl;
            }
            break;
        case 1:
            fileInput.open(middleLeftPath);
            if (fileInput.fail()){ 
                std::cerr << "middle left path failed to open" << std::endl;
            }
            break;
        case 2:
            fileInput.open(bottomLeftPath);
            if (fileInput.fail()){ 
                std::cerr << "bottom left path failed to open" << std::endl;
            }
            break;
        default:
            std::cout << "error opening filePath" << std::endl;
            break;
        }

        while(getline(fileInput, input)){
            generatedLevel.push_back(input);
        }

        fileInput.close();
    }
}

void LevelGenerator::GenerateMiddleColumn(){
    std::ifstream fileInput;
    int index = 0;
    std::string input;

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            fileInput.open(topMiddlePath);
            if (fileInput.fail()){ 
                std::cerr << "Top Middle Path failed to open" << std::endl;
            }
            break;
        case 1:
            fileInput.open(middleMiddlePath);
            if (fileInput.fail()){ 
                std::cerr << "Middle middle Path failed to open" << std::endl;
            }
            break;
        case 2:
            fileInput.open(middleBottomPath);
            if (fileInput.fail()){ 
                std::cerr << "Middle Bottom Path failed to open" << std::endl;
            }
            break;
        
        default:
            std::cerr << "middle column map generation switch out of range" << std::endl;
            break;
        }

        while(getline(fileInput, input)){
            generatedLevel[index] += input;
            index ++;
        }

        fileInput.close();
    }
}

void LevelGenerator::GenerateRightColumn(){
    std::ifstream fileInput;
    int index = 0;
    std::string input;

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            fileInput.open(topRightPath);
            if (fileInput.fail()){ 
                std::cerr << "Top Right Path failed to open" << std::endl;
            }
            break;
        case 1:
            fileInput.open(middleRightPath);
            if (fileInput.fail()){ 
                std::cerr << "Middle Right Path failed to open" << std::endl;
            }
            break;
        case 2:
            fileInput.open(bottomRightPath);
            if (fileInput.fail()){ 
                std::cerr << "bottom Right Path failed to open" << std::endl;
            }
            break;
        
        default:
            std::cerr << "Right column map generation switch out of range" << std::endl;
            break;
        }

        while(getline(fileInput, input)){
            generatedLevel[index] += input;
            index ++;
        }

        fileInput.close();
    }
}

void LevelGenerator::DisplayLevel(){
    for (int i = 0; i < generatedLevel.size(); i++)
        {
            std::cout << generatedLevel[i] << std::endl;
        }
}