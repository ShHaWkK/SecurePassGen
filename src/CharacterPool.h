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

    std::vector<char> getLetters() const;
    std::vector<char> getDigits() const;
    std::vector<char> getSymbols() const;

private:
    std::vector<char> letters;
    std::vector<char> digits;
    std::vector<char> symbols;
};


#endif //CHARACTERPOOL_H

