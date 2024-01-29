//
// Created by ShHawk on 29/01/2024.
//

#ifndef CHARACTERPOOL_H
#define CHARACTERPOOL_H

#include <string>
#include <vector>

class CharacterPool {
public:
    CharacterPool();
    std::vector<char> getCharacters() const;
private:
    std::vector<char> characters;
};

#endif //CHARACTERPOOL_H

