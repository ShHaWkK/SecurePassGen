//
// Created by ShHawk on 29/01/2024.
//


#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <string>
#include "CharacterPool.h"

class PasswordGenerator {
public:
    PasswordGenerator();
    std::string generate(int length);
private:
    CharacterPool characterPool;
};

#endif //PASSWORDGENERATOR_H

