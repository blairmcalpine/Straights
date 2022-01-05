#ifndef ORDEREDPILE_H
#define ORDEREDPILE_H

#include "pile.h"

class OrderedPile: public Pile {
    char suit;
    bool canAddFront(const Card& card) const;
    bool canAddBack(const Card& card) const;
    public:
        OrderedPile(char suit); // create an orderedpile of specified suit
        bool addCard(const Card& card); // returns true if card was successfully added
        bool canAdd(const Card& card) const; // returns true if card can be added
};

#endif
