#include "straights.h"
#include "card.h"
#include "pile.h"
#include "human.h"
#include "computer.h"
#include "observer.h"
#include "suits.h"
#include "ranks.h"
#include "orderedpile.h"
#include "deck.h"
#include <iostream>

void Straights::illegalInput() {
    for (auto &o : observers) {
        o->illegalInput();
    }
}

void Straights::showPiles() {
    for (auto &o : observers) {
        o->showPiles(piles);
    }
}

void Straights::showPlayable(const Pile &playable, const Pile &hand) {
    for (auto &o : observers) {
        o->showPlayable(playable, hand);
    }
}

void Straights::illegalPlay() {
    for (auto &o : observers) {
        o->illegalPlay();
    }
}

void Straights::illegalDiscard() {
    for (auto &o : observers) {
        o->illegalDiscard();
    }
}

void Straights::showDeck() {
    for (auto &o : observers) {
        o->showDeck(deck);
    }
}

void Straights::playCard(const Card& card) {
    for (auto &o : observers) {
        o->playCard(card, current_player);
    }
}

void Straights::discardCard(const Card& card) {
    for (auto &o : observers) {
        o->discardCard(card, current_player);
    }
}

void Straights::askPlayer(const int i) {
    for (auto &o : observers) {
        o->askPlayer(i);
    }
}

void Straights::firstPlayer(const int i) {
    for (auto &o : observers) {
        o->firstPlayer(i);
    }
}

void Straights::showDiscard(const Pile& discard) {
    for (auto &o : observers) {
        o->showDiscard(discard, current_player);
    }
}

void Straights::showScore(const int old_score, const int added) {
    for (auto &o : observers) {
        o->showScore(old_score, added, current_player);
    }
}

void Straights::end() {
    play = false;
}

void Straights::ragequit(Pile& hand, Pile& discard, int points) {
    std::unique_ptr<Player> replacement = std::make_unique<Computer>(discard, hand, points, this);
    players[current_player-1] = std::move(replacement);
    for (auto &o : observers) {
        o->ragequit(current_player);
    }
    players[current_player-1]->playRound();
}

Straights::Straights(unsigned int seed, const int player_count, const int max_score): 
    deck{Deck{seed}}, 
    current_player{-1},
    player_count{player_count},
    max_score{max_score}, 
    play{true} {
    if (player_count < 2) throw std::out_of_range("Must be at least two players");
    if (max_score < 1) throw std::out_of_range("Max score must be at least 1");
    for (auto &suit : suits::suits) {
        piles.emplace_back(suit);
    }
}

void Straights::getPlayers() {
    char c;
    for (int i = 1; i <= player_count; ++i) {
        askPlayer(i);
        std::cin >> c;
        while (c != 'h' && c != 'c') {
            illegalInput();
            askPlayer(i);
            std::cin >> c;
        }
        if (c == 'h') {
            players.push_back(std::make_unique<Human>(this));
        }
        else {
            players.push_back(std::make_unique<Computer>(this));
        }
    }
}

void Straights::findWinner(const std::vector<int>& scores) {
    int min = scores[0];
    for (auto &score : scores) { // find lowest score
        if (score < min) min = score;
    }
    std::vector<int> winners;
    for (int i = 1; i <= scores.size(); ++i) { // find all players with lowest score
        if (scores[i-1] == min) winners.emplace_back(i);
    }
    for (auto &o : observers) {
        o->showWinner(winners);
    }
}

void Straights::startGame() {
    getPlayers();
    int max_cards = ranks::MAX_RANK * suits::suits.size();
    int cards_per = max_cards / players.size();
    std::vector<int> scores;
    while (play) {
        int j = 1;
        scores.clear();
        deck.shuffle();
        for (auto &p : players) { // deal cards to players
            for (int i = 0; i < cards_per; ++i) {
                Card card = deck.draw();
                p->giveCard(card);
                if (card == Card{ranks::START_RANK, suits::START_SUIT}) current_player = j; // set current player to whoever has starting card
            }
            ++j;
        }
        firstPlayer(current_player);
        int cards_played = 0;
        while (cards_played < (cards_per*players.size()) && play) { // play until quit or all cards have been played
            players[current_player-1]->playRound();
            ++current_player;
            if (current_player > players.size()) current_player = 1;
            ++cards_played;
        }
        if (!play) return; // exit now if quit command is entered
        current_player = 1;
        for (auto &p : players) { // reset each player
            p->reset();
            ++current_player;
            if (current_player > players.size()) current_player = 1;
        }
        piles.clear(); // reset piles
        for (auto &suit : suits::suits) {
            piles.emplace_back(suit);
        } 
        for (auto &p : players) { // check if anyone has reached max_score
            int points = p->getPoints();
            if (points > max_score) play = false;
            scores.push_back(points);
        }
    }
    findWinner(scores);
}

void Straights::attach(Observer *o) { observers.emplace_back(o); }

void Straights::detach(Observer *o) {
  for (auto it = observers.begin(); it != observers.end();) {
    if (*it == o) it = observers.erase(it);
    else ++it;
  }
}
