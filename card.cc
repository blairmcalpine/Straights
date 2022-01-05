#include "card.h"
#include "suits.h"
#include "ranks.h"
#include <stdexcept>
#include <string>
#include <ios>

Card::Card(int rank, char suit) {
    if (ranks::validRank(rank)) this->rank = rank;
    else throw std::out_of_range("Given rank is not a valid rank");
    if (suits::validSuit(suit)) this->suit = suit;
    else throw std::out_of_range("Given suit is not a valid suit");
}

Card::Card(): rank{ranks::START_RANK}, suit{suits::START_SUIT} {}

Card Card::operator+(const int n) const {
    int new_rank = rank + n;
    if (new_rank > ranks::MAX_RANK) new_rank = ranks::MAX_RANK; // bounds reduction
    else if (new_rank < ranks::MIN_RANK) new_rank = ranks::MIN_RANK; // bounds reduction
    return Card(new_rank, suit);
}

Card Card::operator-(const int n) const {
    return Card::operator+(n*-1);
}

bool Card::operator==(const Card& rhs) const {
    return rank == rhs.getRank() && suit == rhs.getSuit();
}

bool Card::operator!=(const Card& rhs) const {
    return !(*this == rhs);
}

int Card::getRank() const{
    return rank;
}

char Card::getSuit() const{
    return suit;
}

std::ostream &operator<<(std::ostream& out, const Card& rhs) {
    out << ranks::rankToName.find(rhs.getRank())->second; // output the associated character for this cards rank
    out << rhs.getSuit(); // output the suit
    return out;
}

std::istream &operator>>(std::istream& in, Card& rhs) {
    int rank;
    char next;
    in >> std::skipws >> next; // get first char in stream
    if (!ranks::validRank(next)) { // if not a valid rank, set failbit and return
        in.seekg(0);
        in.setstate(std::ios::failbit);
        return in;
    }
    rank = ranks::nameToRank.find(next)->second; // set rank to associated rank from next
    in >> next; // get second char in stream
    if (!suits::validSuit(next)) { // if not a valid rank, add first char back, set failbit and return
        in.seekg(0);
        in.setstate(std::ios::failbit);
        return in;
    }
    rhs = Card{rank, next};
    return in;
}
