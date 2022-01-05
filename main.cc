#include "straights.h"
#include "textobserver.h"
#include "suits.h"
#include "ranks.h"
#include <string>
#include <chrono>

int main (int argc, char *argv[]) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	int player_count = 4;
	int max_score = 80;
	char suit;
	char rank;
    if (argc > 1) {
		try {
			seed = std::stoi(argv[1]);
		} catch(std::invalid_argument & e) {
			std::cerr << "Invalid seed. Must be an integer." << std::endl;
			return 1;
		} catch(std::out_of_range & e) {
			std::cerr << "Invalid seed. Number is outside range of int." << std::endl;
			return 1;
		}
	}
	if (argc > 2) {
		try {
			player_count = std::stoi(argv[2]);
		} catch(std::invalid_argument & e) {
			std::cerr << "Invalid player count. Must be an integer." << std::endl;
			return 1;
		} catch(std::out_of_range & e) {
			std::cerr << "Invalid player count. Number is outside range of int." << std::endl;
			return 1;
		}
	}
	if (argc > 3) {
		try {
			max_score = std::stoi(argv[3]);
		} catch(std::invalid_argument & e) {
			std::cerr << "Invalid max score. Must be an integer." << std::endl;
			return 1;
		} catch(std::out_of_range & e) {
			std::cerr << "Invalid max score. Number is outside range of int." << std::endl;
			return 1;
		}
	}
	if (argc > 4) {
		suit = argv[4][0];
		if (!suits::charToSuit.count(suit)) {
			suits::suits.emplace_back(suit);
			suits::charToSuit.insert(std::pair<char,std::string>(suit,"Custom Suit"));
		}
	}
	if (argc > 5) {
		rank = argv[5][0];
		if (!ranks::nameToRank.count(rank)) {
			ranks::MAX_RANK++;
			ranks::rankToName.insert(std::pair<int,char>(ranks::MAX_RANK,rank));
			ranks::nameToRank.insert(std::pair<char,int>(rank,ranks::MAX_RANK));
		}
	}
	try {
		Straights game{seed, player_count, max_score};
		TextObserver to{&game};
    	game.startGame();
	}
    catch(std::out_of_range & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
    
}
