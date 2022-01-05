#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"
#include <string>

class Straights;

class Human : public Player {
    void getInput(Card& card, std::string& com); // get input for command and card (if needed) and store it in provided parameters
    public:
        Human(Straights* const game);
        void playRound() override; // plays round
};

#endif
