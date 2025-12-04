// Random playing card generator with separate suit/rank selection.
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    std::vector<std::string> ranks = {"Ace", "2", "3", "4", "5", "6", "7", "8",
                                      "9",  "10", "Jack", "Queen", "King"};

    std::mt19937 rng(static_cast<unsigned long>(
        std::chrono::steady_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> suit_dist(0, static_cast<int>(suits.size()) - 1);
    std::uniform_int_distribution<int> rank_dist(0, static_cast<int>(ranks.size()) - 1);

    std::cout << "Press Enter to draw a card (or Ctrl+D to quit):\n";
    std::string line;
    while (true) {
        std::cout << "> " << std::flush;
        if (!std::getline(std::cin, line)) {
            break;  // EOF (Ctrl+D).
        }

        int suit_idx = suit_dist(rng);
        int rank_idx = rank_dist(rng);
        std::cout << "You drew: " << ranks[rank_idx] << " of " << suits[suit_idx] << "\n";
    }

    std::cout << "Goodbye!\n";
    return 0;
}
