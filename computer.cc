#include "computer.h"
#include "orderedpile.h"
#include "card.h"
#include "pile.h"
#include "straights.h"

Computer::Computer(Straights* const game) {
    this->game = game;
}

Computer::Computer(const Pile& discard, const Pile& hand, const int points, Straights* const game) {
    this->discard = discard;
    this->hand = hand;
    this->points = points;
    this->game = game;
}

void Computer::playRound() {
    Pile playable = Player::playableCards(); // get playable cards
    game->showPiles(); // show piles
    game->showPlayable(playable, hand); // show hand and playable cards in hand
    if (playable.size()) Player::playCard(playable[0]); // play the first playable card if there is one
    else Player::discardCard(hand[0]); // if not discard first card in hand
}
