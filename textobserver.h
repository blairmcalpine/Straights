#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include "observer.h"

class Straights;

class TextObserver : public Observer {
    Straights *subject;
    public:
        TextObserver(Straights*);
        ~TextObserver();
        void illegalInput() override;
        void showPiles(const std::vector<OrderedPile>& piles) override;
        void showPlayable(const Pile& playable, const Pile& hand) override;
        void askPlayer(const int player) override;
        void illegalPlay() override;
        void illegalDiscard() override;
        void ragequit(const int player) override;
        void showDeck(const Deck& deck) override;
        void playCard(const Card& card, const int player) override;
        void discardCard(const Card& card, const int player) override;
        void showDiscard(const Pile& discard, const int player) override;
        void showScore(const int old, const int added, const int player) override;
        void firstPlayer(const int player) override;
        void showWinner(const std::vector<int>& winners) override;
};

#endif
