#include <iostream>
#include <cstdlib>
#include <ctime>

class Coin {
private:
    std::string sideUp;

public:
    // Default constructor
    Coin();

    // Member functions
    void toss();
    std::string getSideUp() const;
};

// Default constructor
Coin::Coin() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Initialize sideUp randomly
    toss();
}

// Toss the coin
void Coin::toss() {
    // Generate a random number (0 or 1)
    int randomNumber = rand() % 2;

    // Set sideUp based on the random number
    sideUp = (randomNumber == 0) ? "heads" : "tails";
}

// Get the current side facing up
std::string Coin::getSideUp() const {
    return sideUp;
}

int main() {
    Coin coin;
    int headsCount = 0, tailsCount = 0;

    // Display the initial side facing up
    std::cout << "Initial side facing up: " << coin.getSideUp() << std::endl;

    // Toss the coin 20 times
    for (int i = 0; i < 20; ++i) {
        coin.toss();
        std::cout << "Toss " << i + 1 << ": " << coin.getSideUp() << std::endl;

        // Count the number of heads and tails
        if (coin.getSideUp() == "heads") {
            headsCount++;
        } else {
            tailsCount++;
        }
    }

    // Display the counts
    std::cout << "\nNumber of times heads is facing up: " << headsCount << std::endl;
    std::cout << "Number of times tails is facing up: " << tailsCount << std::endl;

    return 0;
}
