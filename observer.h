#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

class Pile;
class Deck;
class Card;
class OrderedPile;

class Observer {
    public:
        virtual void illegalInput() = 0; // message for illegal input
        virtual void showPiles(const std::vector<OrderedPile>& piles) = 0; // output piles
        virtual void showPlayable(const Pile& playable, const Pile& hand) = 0; // output hand and what is playable
        virtual void askPlayer(const int player) = 0; // message to ask what kind of player it is
        virtual void illegalPlay() = 0; // message for a play that is valid input but invalid play
        virtual void illegalDiscard() = 0; // message for a discard that is valid input but invalid discard
        virtual void ragequit(const int player) = 0; // message for ragequit
        virtual void showDeck(const Deck& deck) = 0; // output the deck
        virtual void playCard(const Card& card, const int player) = 0; // message for when player plays card
        virtual void discardCard(const Card& card, const int player) = 0; // message for when player discards card
        virtual void showDiscard(const Pile& discard, const int player) = 0; // output discard pile of player
        virtual void showScore(const int old, const int added, const int player) = 0; // output score of player
        virtual void firstPlayer(const int player) = 0; // message for which player goes first
        virtual void showWinner(const std::vector<int>& winners) = 0; // message for showing winner(s)
        virtual ~Observer() = default;
};

#endif
