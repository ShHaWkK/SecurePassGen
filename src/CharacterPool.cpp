//
// Created by alexa on 29/01/2024.
//

#include "CharacterPool.h"


CharacterPool::CharacterPool() {
    // Initialisation avec un ensemble standard de caractères
    for (char c = '0'; c <= '9'; ++c) characters.push_back(c);
    for (char c = 'A'; c <= 'Z'; ++c) characters.push_back(c);
    for (char c = 'a'; c <= 'z'; ++c) characters.push_back(c);
    characters.push_back('!');
    characters.push_back('@');
    characters.push_back('#');
    characters.push_back('$');
    characters.push_back('%');
    characters.push_back('^');
    characters.push_back('&');
    characters.push_back('*');
    characters.push_back('(');
    characters.push_back(')');
}

std::vector<char> CharacterPool::getCharacters() const {
    return characters;
}

std::vector<char> CharacterPool::getCharacters() const {
    return characters;
}
