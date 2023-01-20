#ifndef NUMBERGENERATOR_H
#define NUMBERGENERATOR_H

#include <cstdlib>
#include <iostream>
#include <string>

class NumberGenerator
{
private:
    int _seed = 0; 

    //get seed from user input

    void caluclateSeed(std::string seedInput){

        const char* inputCharArray = seedInput.data();

        for (int i = 0; i < seedInput.size(); i++)
        {
            _seed += int(inputCharArray[i]);
        }

        srand(_seed);
    }

public:

    int getIntRanged (int max, int min = 0){
        if (min > max) 
        { std::cerr << "ERROR in RNG. MIN too high. Setting MIN to 0 " << "\n";}

        return rand() % (max + 1 - min) + min;
    }

    NumberGenerator(std::string seedInput) {caluclateSeed(seedInput); };
    
};

#endif