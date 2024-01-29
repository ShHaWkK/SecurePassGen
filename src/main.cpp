// src/main.cpp
#include "PasswordGenerator.h"
#include <iostream>

int main() {
    int length;
    std::cout << "Enter the length of the password: ";
    std::cin >> length;

    PasswordGenerator passwordGenerator;
    std::string password = passwordGenerator.generate(length);
    std::cout << "Generated Password: " << password << std::endl;

    return 0;
}
