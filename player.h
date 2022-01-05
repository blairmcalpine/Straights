#ifndef PLAYER_H
#define PLAYER_H

#include "pile.h"
#include <vector>

class OrderedPile;
class Card;
class Straights;
class PlayerObserver;

class Player {
    protected:
        Pile hand;
        Pile discard;
        int points;
        Straights *game;
        Pile playableCards() const; // returns a Pile of cards from hand that can be played
        bool playCard(const Card& card); // adds card to appropriate OrderedPile if possible, returns true if success
        bool discardCard(const Card& card);  // discards card from hand to discard possible, returns true if successful
    public:
        Player();
        virtual ~Player() = default;
        bool giveCard(const Card& card); // returns true if card is succesfully given to this
        virtual void playRound() = 0; // plays round given current piles
        void reset(); // increments points and resets piles
        int getPoints(); // accessor for points
};

#endif
