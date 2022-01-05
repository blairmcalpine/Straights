#include "textobserver.h"
#include "pile.h"
#include "deck.h"
#include "card.h"
#include "suits.h"
#include <iostream>
#include "orderedpile.h"
#include "straights.h"

TextObserver::TextObserver(Straights *game): subject{game} {
    subject->attach(this);
}

TextObserver::~TextObserver() {
    subject->detach(this);
}

void TextObserver::illegalInput() {
    std::cout << "Invalid Input." << std::endl;
}

void TextObserver::showPiles(const std::vector<OrderedPile>& piles) {
    int i = 0;
    std::cout << "Cards on the table:" << std::endl;
    for (auto &suit : suits::suits) {
        std::cout << suits::charToSuit[suit] << ":" << piles[i] << std::endl;
        ++i;
    }
}

void TextObserver::showPlayable(const Pile& playable, const Pile& hand) {
    std::cout << "Your hand:" << hand << std::endl;
    std::cout << "Legal plays:" << playable << std::endl;
}

void TextObserver::askPlayer(const int player) {
    std::cout << "Is Player" << player << " a human (h) or a computer (c)?" << std::endl;
}

void TextObserver::illegalPlay() {
    std::cout << "This is not a legal play." << std::endl;
}

void TextObserver::illegalDiscard() {
    std::cout << "You have a legal play. You may not discard." << std::endl;
}

void TextObserver::ragequit(const int player) {
    std::cout << "Player" << player << " ragequits. A computer will now take over." << std::endl;
}

void TextObserver::showDeck(const Deck& deck) {
    std::cout << deck << std::endl;
}

void TextObserver::playCard(const Card& card, const int player) {
    std::cout << "Player" << player << " plays " << card << "." << std::endl;
}

void TextObserver::discardCard(const Card& card, const int player) {
    std::cout << "Player" << player << " discards " << card << "." << std::endl;
}

void TextObserver::showDiscard(const Pile& discard, const int player) {
    std::cout << "Player" << player << "'s discards:" << discard << std::endl;
}

void TextObserver::showScore(const int old, const int added, const int player) {
    std::cout << "Player" << player << "'s score: " << old << " + " << added << " = " << (old+added) << std::endl;
}

void TextObserver::firstPlayer(const int player) {
    std::cout << "A new round begins. It's Player" << player << "'s turn to play." << std::endl;
}

void TextObserver::showWinner(const std::vector<int>& winners) {
    for (std::size_t i = 0; i < winners.size(); ++i) {
        std::cout << "Player" << winners[i];
        if (i == winners.size()-1) {
            std::cout << " ";
        }
        else if (i == winners.size()-2) {
            std::cout << " and ";
        }
        else {
            std::cout << ", ";
        }
    }
    std::cout << "win";
    if (winners.size() == 1) std::cout << "s";
    std::cout << "!" << std::endl;
}
