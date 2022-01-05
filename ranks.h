#ifndef RANKS_H
#define RANKS_H

#include <map>

namespace ranks {
    extern int MAX_RANK; // max possible rank
    extern int MIN_RANK; // min possible rank
    extern int START_RANK; // rank that must be started with
    extern std::map<int, char>rankToName; // map from rank to associated char (eg. 11 to J for jack)
    extern std::map<char, int>nameToRank; // map from char to associated rank (eg. J to 11 for jack)
    bool validRank(int); // returns true if int is a valid rank
    bool validRank(char); // returns true if char is a valid rank
};

#endif
