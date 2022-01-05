#include "deck.h"
#include "card.h"
#include "suits.h"
#include "ranks.h"
#include <algorithm>
#include <stdexcept>
#include <random>

Deck::Deck(unsigned int seed): seed{seed}, current{0}, theDeck{std::vector<Card>()} {
    for (auto &suit : suits::suits) { // create deck with all cards from all suits in order
        for (int i = ranks::MIN_RANK; i <= ranks::MAX_RANK; ++i) {
            theDeck.emplace_back(i, suit);
        }
    }
}

void Deck::shuffle() {
    std::default_random_engine rng{seed};
    std::shuffle(theDeck.begin(), theDeck.end(), rng);
    current = 0; // reset position of drawn card
}

Card Deck::draw() {
    if (current == theDeck.size()) throw std::out_of_range("Deck is empty");
    return theDeck[current++]; // return card, increment current after
}

std::ostream &operator<<(std::ostream& out, const Deck& deck) {
    for (std::size_t i = 0; i < deck.theDeck.size(); ++i) {
        out << deck.theDeck[i];
        if ((i+1) % ranks::MAX_RANK == 0 && (i+1) != deck.theDeck.size()) out << '\n'; // go to new line
        else out << ' ';
    }
    return out;
}
