// src/PasswordGenerator.cpp
#include "PasswordGenerator.h"
#include <fstream>

PasswordGenerator::PasswordGenerator() : gen(rd()) {
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
void PasswordGenerator::savePasswordsToFile(const std::vector<std::string>& passwords, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        for (const auto& password : passwords) {
            file << password << std::endl;
        }
        file.close();
    } else {
    }
}
bool PasswordGenerator::isValid(const std::string& password, int minLetters, int minDigits, int minSymbols) {
    int countLetters = 0, countDigits = 0, countSymbols = 0;
    for (char c : password) {
        if (std::isalpha(c)) ++countLetters;
        else if (std::isdigit(c)) ++countDigits;
        else ++countSymbols;
    }
    return countLetters >= minLetters && countDigits >= minDigits && countSymbols >= minSymbols;
}