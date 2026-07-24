#include <unordered_map>
#include <string>
#include <vector>

class CardManager {
private:
    std::unordered_map<std::string, int> prices = 
    {
        {"+1", 2},
        {"Invert Order", 2},
        {"x2", 4},
        {"x10", 9}
    };

public:
    int getPrice(const std::string& cardName) const;
    bool exists(const std::string& cardName) const;
    std::vector<std::string> getCardNames() const;
    void runCard(const std::string& cardName, int* pts, int* elixir);
};