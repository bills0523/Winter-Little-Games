// Alphabet typing speed game with best-time tracking.
#include <algorithm>
#include <chrono>
#include <cctype>
#include <iostream>
#include <string>

int main() {
    constexpr char expected[] = "abcdefghijklmnopqrstuvwxyz";
    bool has_best = false;
    double best_time = 0.0;

    std::cout << "Typing Speed Test: type the alphabet as fast as you can (case-insensitive).\n";

    while (true) {
        std::cout << "[Enter] to start, 'b' then Enter to see best time, Ctrl+C to quit.\n";
        std::cout << "Press Enter when you're ready..." << std::flush;
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cerr << "\nInput ended. Exiting.\n";
            return 1;
        }

        if (line == "b" || line == "B") {
            if (has_best) {
                std::cout << "Best time so far: " << best_time << " seconds.\n\n";
            } else {
                std::cout << "No best time recorded yet. Play a round first.\n\n";
            }
            continue;
        }

        std::cout << "Go! Type the alphabet and press Enter:\n> " << std::flush;
        auto start = std::chrono::steady_clock::now();
        if (!std::getline(std::cin, line)) {
            std::cerr << "\nInput ended. Exiting.\n";
            return 1;
        }
        auto end = std::chrono::steady_clock::now();

        // Normalize to lowercase for comparison.
        std::string normalized = line;
        std::transform(normalized.begin(), normalized.end(), normalized.begin(),
                       [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });

        if (normalized != expected) {
            std::cout << "That wasn't the alphabet exactly. Try again.\n\n";
            continue;
        }

        std::chrono::duration<double> elapsed = end - start;
        double seconds = elapsed.count();

        bool new_best = false;
        if (!has_best || seconds < best_time) {
            best_time = seconds;
            has_best = true;
            new_best = true;
        }

        std::cout << "Nice! You typed the alphabet in " << seconds
                  << " seconds. The current best time is " << best_time << " seconds.\n";
        if (new_best) {
            std::cout << "New best time!\n";
        }
        std::cout << '\n';
    }

    return 0;
}
