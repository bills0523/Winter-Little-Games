#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

int main() {
    while (true) {
        std::string sentence;
        std::cout << "Enter a sentence: " << std::flush;
        if (!std::getline(std::cin, sentence)) {
            std::cerr << "Failed to read input.\n";
            return 1;
        }

        std::istringstream words(sentence);
        std::string word;
        std::size_t count = 0;

        while (words >> word) {
            ++count;
        }

        std::cout << "Number of words: " << count << '\n';

        while (true) {
            std::cout << "Count another? (y/n): " << std::flush;
            std::string again;
            if (!std::getline(std::cin, again)) {
                std::cerr << "Failed to read input.\n";
                return 1;
            }

            // Skip leading whitespace before checking the first character.
            std::size_t pos = 0;
            while (pos < again.size() && std::isspace(static_cast<unsigned char>(again[pos]))) {
                ++pos;
            }
            if (pos == again.size()) {
                continue; // Empty response; ask again.
            }

            char c = static_cast<char>(std::tolower(static_cast<unsigned char>(again[pos])));
            if (c == 'y') {
                break; // Continue outer loop.
            }
            if (c == 'n') {
                return 0; // Exit the program.
            }
            // Invalid entry; loop again to ask.
        }
    }
    return 0;
}
