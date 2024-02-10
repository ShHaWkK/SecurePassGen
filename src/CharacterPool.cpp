/**********************************************************************/                                                    */
/* Date :  29/01/2024                                                 */
/* author : ShHaWkK                                                   */
/**********************************************************************/

/*
*Include 
*/
#include "CharacterPool.h"

//---------------    CharacterPool    ---------------//      
CharacterPool::CharacterPool() 
{
    for (char c = 'a'; c <= 'z'; ++c) letters.push_back(c);
    for (char c = 'A'; c <= 'Z'; ++c) letters.push_back(c);
    for (char c = '0'; c <= '9'; ++c) digits.push_back(c);
    symbols = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
}

std::vector<char> CharacterPool::getLetters() const { return letters; }
std::vector<char> CharacterPool::getDigits() const { return digits; }
std::vector<char> CharacterPool::getSymbols() const { return symbols; }

