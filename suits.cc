#include "suits.h"
#include <algorithm>

char suits::START_SUIT = 'S';

std::vector<char>suits::suits{'C','D','H','S'};

std::map<char, std::string>suits::charToSuit{
    {'C',"Clubs"},
    {'D',"Diamonds"},
    {'H',"Hearts"},
    {'S',"Spades"}
};

bool suits::validSuit(char c) {
    return (std::count(suits::suits.begin(), suits::suits.end(), c));
}
