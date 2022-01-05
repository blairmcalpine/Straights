#include "ranks.h"
#include <stdexcept>

int ranks::MIN_RANK = 1;

int ranks::MAX_RANK = 13;

int ranks::START_RANK = 7;

std::map<int, char>ranks::rankToName{
    {1,'A'}, {2,'2'}, {3,'3'},
    {4,'4'}, {5,'5'}, {6,'6'},
    {7,'7'}, {8,'8'}, {9,'9'},
    {10,'T'}, {11,'J'}, {12,'Q'},
    {13,'K'}
};

std::map<char, int>ranks::nameToRank{
    {'A',1}, {'2',2}, {'3',3},
    {'4',4}, {'5',5}, {'6',6},
    {'7',7}, {'8',8}, {'9',9},
    {'T',10}, {'J',11}, {'Q',12},
    {'K',13}
};

bool ranks::validRank(int n) {
    return (ranks::rankToName.find(n) != ranks::rankToName.end());
}

bool ranks::validRank(char c) {
    return (ranks::nameToRank.find(c) != ranks::nameToRank.end());
}
