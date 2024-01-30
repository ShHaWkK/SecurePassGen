// src/PasswordGenerator.cpp
#include "PasswordGenerator.h"
#include <algorithm>
#include <iterator>
#include <vector>

PasswordGenerator::PasswordGenerator() : gen(rd()) {
    // Configuration initiale si nécessaire
}

char PasswordGenerator::getRandomChar(const std::vector<char>& chars) {
    std::uniform_int_distribution<> dis(0, chars.size() - 1);
    return chars[dis(gen)];
}

std::string PasswordGenerator::generate(int length, int minLetters, int minDigits, int minSymbols) {
    std::string password;
    password.reserve(length);

    // Ajouter le nombre minimum requis de chaque type de caractère
    for (int i = 0; i < minLetters; ++i) password.push_back(getRandomChar(characterPool.getLetters()));
    for (int i = 0; i < minDigits; ++i) password.push_back(getRandomChar(characterPool.getDigits()));
    for (int i = 0; i < minSymbols; ++i) password.push_back(getRandomChar(characterPool.getSymbols()));

    // Remplir le reste du mot de passe avec des caractères aléatoires de tous types
    while (password.size() < length) {
        password.push_back(getRandomChar(characterPool.getLetters()));
        if (password.size() < length) password.push_back(getRandomChar(characterPool.getDigits()));
        if (password.size() < length) password.push_back(getRandomChar(characterPool.getSymbols()));
    }

    // Mélanger le mot de passe pour éviter les modèles prévisibles
    std::shuffle(password.begin(), password.end(), gen);

    return password;
}