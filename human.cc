#include "human.h"
#include "orderedpile.h"
#include "card.h"
#include "straights.h"
#include <string>
#include <limits>

Human::Human(Straights* const game){
    this->game = game;
};

void Human::getInput(Card& card, std::string& com) {
    std::string command;
    Card c;
    bool validInput = false;
    while(!validInput) {
        std::cin >> command;
        if (command != "play" && command != "discard" &&
            command != "deck" && command != "quit" &&
            command != "ragequit") {
            game->illegalInput();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (command == "play" || command == "discard") { // get card if needed
            std::cin >> c;
            if (!std::cin.good()) {
                game->illegalInput();
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }
        validInput = true;
    }
    if (command == "play" || command == "discard") card = c;
    com = command;
}

void Human::playRound() {
    Pile playable = Player::playableCards(); // get playable cards
    game->showPiles(); // show piles
    game->showPlayable(playable, hand); // show hand and playable cards in hand
    std::string command;
    Card c;
    bool validInput = false;
    while (!validInput) {
        validInput = true;
        getInput(c, command);
        if (command == "play") {
            if (!hand.inPile(c)) {game->illegalInput(); validInput = false;} // check if inputted card isnt in hand
            else if (!playable.inPile(c)) {game->illegalPlay(); validInput = false;} // check if inputted card isnt playable
            else Player::playCard(c);
        }
        else if (command == "discard") {
            if (!hand.inPile(c)) {game->illegalInput(); validInput = false;} // check if inputted card isnt in hand
            else if (playable.size() != 0) {game->illegalDiscard(); validInput = false;} // check if there is a playable card
            else Player::discardCard(c);
        }
        else if (command == "deck") {game->showDeck(); validInput = false;} // show deck, mark validInput as false to get another input
        else if (command == "quit") game->end();
        else if (command == "ragequit") game->ragequit(hand, discard, points);
    }
}
