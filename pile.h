#ifndef PILE_H
#define PILE_H

#include <vector>
#include <iostream>

class Card;

class Pile {
    friend std::ostream &operator<<(std::ostream& out, const Pile& pile);
    protected:
        std::vector<Card> thePile;
    public:
        Pile();
        bool inPile(const Card& card); // returns true if card is in the Pile
        bool addCard(const Card& card); // returns true if card was successfully added
        bool removeCard(const Card& card); // returns true if card was successfuly removed
        int size() const; // returns size of thePile
        Card operator[](const int n) const; // returns card in nth index of pile
};

#endif
