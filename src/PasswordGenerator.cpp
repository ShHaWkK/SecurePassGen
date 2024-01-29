// src/PasswordGenerator.cpp
#include "PasswordGenerator.h"
#include <random>

PasswordGenerator::PasswordGenerator() : characterPool() {
}

std::string PasswordGenerator::generate(int length) {
    std::string password;
    std::vector<char> characters = characterPool.getCharacters();
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    for (int i = 0; i < length; ++i) {
        password += characters[distribution(generator)];
    }

    return password;
}
