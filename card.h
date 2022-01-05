#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
    int rank;
    char suit;
    friend std::ostream &operator<<(std::ostream& out, const Card& rhs);
    friend std::istream &operator>>(std::istream& in, Card& rhs);
    public:
        Card(int, char);
        Card();
        Card operator+(const int n) const; // returns card with increased rank
        Card operator-(const int n) const; // returns card with decreased rank
        bool operator==(const Card& rhs) const;
        bool operator!=(const Card& rhs) const;
        int getRank() const; // accessor for rank
        char getSuit() const; // accessor for suit
};

#endif
