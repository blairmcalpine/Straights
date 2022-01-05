#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class Computer : public Player {
    public:
        Computer(Straights* const game);
        Computer(const Pile& discard, const Pile& hand, const int points, Straights* const game); // constructor for creating a computer with non-new data from a ragequit
        void playRound() override; // plays round
};

#endif
