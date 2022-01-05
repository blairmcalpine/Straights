#include "player.h"
#include "orderedpile.h"
#include "card.h"
#include "straights.h"
#include <iostream>
#include "ranks.h"
#include "suits.h"

Player::Player() {
    game = nullptr;
    points = 0;
    hand = Pile{};
    discard = Pile{};
}

Pile Player::playableCards() const {
    Pile cards;
    for (int i = 0; i < hand.size(); ++i) { // iterate through hand
        if (hand[i] == Card{ranks::START_RANK, suits::START_SUIT}) { // check if starting card is in hand
            Pile new_cards;
            new_cards.addCard(hand[i]);
            return new_cards; // return only starting card
        }
        for (auto &pile : game->piles) {
            if (pile.canAdd(hand[i])) cards.addCard(hand[i]); // if current card is playable in a pile, add it to cards
        } 
    }
    return cards;
}

bool Player::playCard(const Card& card) {
    for (auto &pile : game->piles) {
        if (pile.canAdd(card) && hand.removeCard(card)) { // check if card can be added to pile and player has card
            pile.addCard(card);
            game->playCard(card);
            return true;
        }
    }
    return false;
}

bool Player::discardCard(const Card& card) {
    if (hand.removeCard(card)) { // check if card can be removed from hand
        if (discard.addCard(card)) {game->discardCard(card); return true;} // check if card can be added to discard
        else hand.addCard(card); // if not, add back to hand
    }
    return false;
}

bool Player::giveCard(const Card& card) {
    return hand.addCard(card);
}

void Player::reset() {
    game->showDiscard(discard);
    Pile empty;
    int old_points = points;
    int added = 0;
    for (int i = 0; i < discard.size(); ++i) { // add rank of each card to points
        added += discard[i].getRank();
    }
    game->showScore(old_points, added);
    points += added;
    discard = empty; // reset discard
    hand = empty; // reset hand
}

int Player::getPoints() {
    return points;
}
