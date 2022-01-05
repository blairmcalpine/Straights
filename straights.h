#ifndef STRAIGHTS_H
#define STRAIGHTS_H

#include <vector>
#include <memory>
#include "deck.h"
#include "orderedpile.h"
#include "player.h"

class Computer;
class Human;
class Observer;
class Card;
class Pile;

class Straights {
    std::vector<Observer*> observers;
    std::vector<std::unique_ptr<Player>> players;
    std::vector<OrderedPile> piles;
    Deck deck;
    int current_player;
    const int player_count;
    const int max_score;
    bool play;
    friend class Player;
    friend class Computer;
    friend class Human;
    void illegalInput();
    void showPiles();
    void showPlayable(const Pile &, const Pile &);
    void askPlayer(const int);
    void illegalPlay();
    void illegalDiscard();
    void showDeck();
    void end();
    void ragequit(Pile&, Pile&, int);
    void playCard(const Card&);
    void discardCard(const Card&);
    void showDiscard(const Pile&);
    void showScore(const int, const int);
    void getPlayers();
    void firstPlayer(const int);
    void findWinner(const std::vector<int>&);
    public:
        Straights(unsigned int seed, const int player_count = 4, const int max_score = 80); // constructor with seed and player count
        void startGame(); // starts game
        void attach(Observer * o);
        void detach(Observer * o);
        ~Straights() = default;
};

#endif
