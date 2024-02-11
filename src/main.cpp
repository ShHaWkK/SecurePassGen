#include "CharacterPool.h"
#include "PasswordGenerator.h"
#include <iostream>

int main() {
    PasswordGenerator passwordGenerator;
    int numberOfPasswords, length, minLetters, minDigits, minSymbols;

    std::cout << "Enter the number of passwords to generate: ";
    std::cin >> numberOfPasswords;
    std::cout << "Enter the length of each password: ";
    std::cin >> length;


    auto passwords = passwordGenerator.generateMultiple(numberOfPasswords, length, minLetters, minDigits, minSymbols);

    std::string saveOption;
    std::cout << "Do you want to save the passwords to a file? (yes/no): ";
    std::cin >> saveOption;
    if (saveOption == "yes") {
        std::string filename;
        std::cout << "Enter the filename to save passwords: ";
        std::cin >> filename;
        passwordGenerator.savePasswordsToFile(passwords, filename);
    }

    
    for (const auto& password : passwords) {
        std::cout << password << std::endl;
    }

    return 0;
}
