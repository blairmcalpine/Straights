#include "pile.h"
#include "card.h"

Pile::Pile(): thePile{std::vector<Card>()} {}

bool Pile::inPile(const Card& card) {
    for (auto &c : thePile) {
        if (c == card) return true;
    }
    return false;
}

bool Pile::addCard(const Card& card) {
    if (inPile(card)) return false;
    Card new_card = card;
    thePile.push_back(new_card);
    return true;
}

bool Pile::removeCard(const Card& card) {
    for (std::size_t i = 0; i < thePile.size(); ++i) { // check if card exists
        if (thePile[i] == card) {
            thePile.erase(thePile.begin()+i); // remove card
            return true;
        }
    }
    return false;
}

std::ostream &operator<<(std::ostream& out, const Pile& pile) {
    for (auto &card : pile.thePile) {
        out << ' ';
        out << card;
    }
    return out;
}

int Pile::size() const {
    return thePile.size();
}

Card Pile::operator[](const int n) const {
    return thePile[n];
}
