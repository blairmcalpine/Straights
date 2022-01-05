#include "orderedpile.h"
#include "card.h"
#include "ranks.h"
#include "suits.h"

OrderedPile::OrderedPile(char suit) {
    if (suits::validSuit(suit)) this->suit = suit;
    else throw std::out_of_range("Given suit is not a valid suit");
}

bool OrderedPile::addCard(const Card& card) {
    if (canAddFront(card)) {
        Card new_card = card;
        thePile.push_back(new_card);
        return true;
    }
    if (canAddBack(card)) {
        Card new_card = card;
        thePile.insert(thePile.begin(), new_card);
        return true;
    }
    return false;
}

bool OrderedPile::canAdd(const Card& card) const {
    return (canAddFront(card) || canAddBack(card));
}

bool OrderedPile::canAddFront(const Card& card) const {
    if (thePile.size() == 0) return (card == Card{ranks::START_RANK, suit}); // if pile is empty, can play if it is the starting rank
    return (card == thePile[thePile.size()-1]+1 && card != thePile[thePile.size()-1]); // otherwise can play if it one higher than last card
}

bool OrderedPile::canAddBack(const Card& card) const {
    if (thePile.size() == 0) return (card == Card{ranks::START_RANK, suit}); // if pile is empty, can play if it is the starting rank
    return (card == thePile[0]-1 && card != thePile[0]); // otherwise can play if it is one lower than last card
}
