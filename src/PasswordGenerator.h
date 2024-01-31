//
// Created by ShHawk on 29/01/2024.
//


#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include "CharacterPool.h"
#include <algorithm>
#include <string>
#include <iterator>
#include <vector>
#include <random>

class PasswordGenerator {
public:
    PasswordGenerator();
    std::string generate(int length, int minLetters = 0, int minDigits = 0, int minSymbols = 0);
    std::vector<std::string> generateMultiple(int numberOfPasswords, int length, int minLetters, int minDigits, int minSymbols);
    void savePasswordsToFile(const std::vector<std::string>& passwords, const std::string& filename);
    bool isValid(const std::string& password, int minLetters, int minDigits, int minSymbols);
private:
    CharacterPool characterPool;
    std::random_device rd;
    std::mt19937 gen;
    char getRandomChar(const std::vector<char>& chars);
};


#endif //PASSWORDGENERATOR_H

