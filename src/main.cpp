#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "../include/cards.hpp"
#include "../include/style.hpp"

int main(void) {
    CardManager cards;
    int elixir = 10;
    int pts = 0;
    bool isrunning = true;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    while (isrunning) {
        logInfo("You have " + std::to_string(elixir) + " elixir. Decide between these cards:\n");

        auto allCards = cards.getCardNames();
        std::vector<std::string> choices;
        while (choices.size() < 3 && !allCards.empty()) {
            int index = std::rand() % allCards.size();
            choices.push_back(allCards[index]);
            allCards.erase(allCards.begin() + index);
        }

        for (size_t i = 0; i < choices.size(); ++i) {
            std::cout << i + 1 << ") " << choices[i]
                      << " (cost " << cards.getPrice(choices[i]) << ")\n";
        }

        std::cout << "Choose a card by number: ";
        int selection = 0;
        std::cin >> selection;

        if (selection >= 1 && selection <= static_cast<int>(choices.size())) {
            cards.runCard(choices[selection - 1], &pts, &elixir);
            std::cout << "Points: " << pts << ", Elixir: " << elixir << "\n";
        } else {
            logError("Invalid choice.\n");
        }

        if (elixir <= 0) {
            logError("Out of elixir. Game over.\n");
            isrunning = false;
        }
    }
}
