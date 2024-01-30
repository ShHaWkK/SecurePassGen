// src/PasswordGenerator.cpp
#include "PasswordGenerator.h"


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

    for (int i = 0; i < minLetters; ++i) password.push_back(getRandomChar(characterPool.getLetters()));
    for (int i = 0; i < minDigits; ++i) password.push_back(getRandomChar(characterPool.getDigits()));
    for (int i = 0; i < minSymbols; ++i) password.push_back(getRandomChar(characterPool.getSymbols()));

    while (password.size() < length) {
        password.push_back(getRandomChar(characterPool.getLetters()));
        if (password.size() < length) password.push_back(getRandomChar(characterPool.getDigits()));
        if (password.size() < length) password.push_back(getRandomChar(characterPool.getSymbols()));
    }

    std::shuffle(password.begin(), password.end(), gen);

    return password;
}

std::vector<std::string> PasswordGenerator::generateMultiple(int numberOfPasswords, int length, int minLetters, int minDigits, int minSymbols) {
    std::vector<std::string> passwords;
    for (int i = 0; i < numberOfPasswords; ++i) {
        passwords.push_back(generate(length, minLetters, minDigits, minSymbols));
    }
    return passwords;
}
