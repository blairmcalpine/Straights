#ifndef DECK_H
#define DECK_H

#include <vector>
#include <iostream>
#include "card.h"

class Deck {
    unsigned int seed;
    int current;
    std::vector<Card> theDeck;
    friend std::ostream &operator<<(std::ostream& out, const Deck& deck);
    public:
        Deck(unsigned int seed); // constructor with seed
        void shuffle(); // shuffle the deck, reset draw mechanic
        Card draw(); // draw top card from deck
};

#endif
