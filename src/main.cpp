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
    // Demandez minLetters, minDigits, minSymbols de la même manière

    auto passwords = passwordGenerator.generateMultiple(numberOfPasswords, length, minLetters, minDigits, minSymbols);

    // Optionnellement, demandez si l'utilisateur veut sauvegarder les mots de passe
    std::string saveOption;
    std::cout << "Do you want to save the passwords to a file? (yes/no): ";
    std::cin >> saveOption;
    if (saveOption == "yes") {
        std::string filename;
        std::cout << "Enter the filename to save passwords: ";
        std::cin >> filename;
        passwordGenerator.savePasswordsToFile(passwords, filename);
    }

    // Affichez les mots de passe générés
    for (const auto& password : passwords) {
        std::cout << password << std::endl;
    }

    return 0;
}
