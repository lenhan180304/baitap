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
    Coin quarter, dime, nickel;
    double balance = 0.0;

    // Play the game until the balance reaches $1 or more
    while (balance < 1.0) {
        quarter.toss();
        dime.toss();
        nickel.toss();

        // Check the results of the coin tosses and update the balance
        if (quarter.getSideUp() == "heads") {
            balance += 0.25;
        }
        if (dime.getSideUp() == "heads") {
            balance += 0.10;
        }
        if (nickel.getSideUp() == "heads") {
            balance += 0.05;
        }

        // Display the current balance
        std::cout << "Current Balance: $" << balance << std::endl;
    }

    // Determine the game result
    if (balance == 1.0) {
        std::cout << "Congratulations! You win the game!" << std::endl;
    } else {
        std::cout << "Sorry, you lose. Your balance exceeded $1." << std::endl;
    }

    return 0;
}
