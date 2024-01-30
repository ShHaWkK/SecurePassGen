//
// Created by ShHawk on 29/01/2024.
//


#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <string>
#include "CharacterPool.h"
#include <random>

class PasswordGenerator {
public:
    PasswordGenerator();
    std::string generate(int length, int minLetters = 0, int minDigits = 0, int minSymbols = 0);

private:
    CharacterPool characterPool;
    std::random_device rd;
    std::mt19937 gen;
    char getRandomChar(const std::vector<char>& chars);
};


#endif //PASSWORDGENERATOR_H

