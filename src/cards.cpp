#include <unordered_map>
#include <string>
#include <iostream>
#include "../include/cards.hpp"


int CardManager::getPrice(const std::string& cardName) const {
    return prices.at(cardName);
}
bool CardManager::exists(const std::string& cardName) const {
    return prices.count(cardName) == 1;
}
std::vector<std::string> CardManager::getCardNames() const {
    std::vector<std::string> names;
    names.reserve(prices.size());
    for (const auto& pair : prices) {
        names.push_back(pair.first);
    }
    return names;
}
void CardManager::runCard(const std::string& cardName, int* pts, int* elixir) {
    if (!exists(cardName)) {
        return;
    }

    *elixir -= getPrice(cardName);
    if (cardName == "+1") {
        *pts += 1;
    } else if (cardName == "x2") {
        *pts *= 2;
    } else if (cardName == "x10") {
        *pts *= 10;
    } else if (cardName == "Invert Order") {
        int reversed = 0;
        int value = *pts;
        while (value != 0) {
            reversed = reversed * 10 + (value % 10);
            value /= 10;
        }
        *pts = reversed;
    }
}