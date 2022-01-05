#ifndef SUITS_H
#define SUITS_H

#include <vector>
#include <map>
#include <string>

namespace suits {
    extern char START_SUIT; // suit to start from
    extern std::vector<char>suits; // vector of valid suits
    extern std::map<char, std::string>charToSuit; // map from char to name of suit
    bool validSuit(char); // returns true if char is a valid suit
};

#endif
