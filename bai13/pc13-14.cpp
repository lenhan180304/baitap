#include <iostream>
#include <cstdlib>
#include <ctime>

class Die {
private:
    int sides;
    int value;

public:
    Die(int numSides);
    void roll();
    int getValue() const;
};

Die::Die(int numSides) {
    if (numSides < 1) {
        sides = 6;  // default to a six-sided die
    } else {
        sides = numSides;
    }

    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Initial roll
    roll();
}

void Die::roll() {
    // Generate a random value between 1 and sides
    value = rand() % sides + 1;
}

int Die::getValue() const {
    return value;
}

int main() {
    Die die(6);
    int fishingPoints = 0;
    char playAgain;

    do {
        std::cout << "Do you want to fish? (y/n): ";
        std::cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y') {
            // Roll the die to simulate fishing
            die.roll();
            int result = die.getValue();

            // Display the result and update fishing points
            switch (result) {
                case 1:
                    std::cout << "You caught a huge fish! +5 points\n";
                    fishingPoints += 5;
                    break;
                case 2:
                    std::cout << "You caught an old shoe! -1 point\n";
                    fishingPoints -= 1;
                    break;
                case 3:
                    std::cout << "You caught a little fish! +2 points\n";
                    fishingPoints += 2;
                    break;
                // Add more cases for other possible items
                default:
                    std::cout << "You caught something! +1 point\n";
                    fishingPoints += 1;
            }
        } else if (playAgain != 'n' && playAgain != 'N') {
            std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    // Display the total fishing points and a congratulatory message
    std::cout << "Total fishing points: " << fishingPoints << std::endl;

    if (fishingPoints >= 10) {
        std::cout << "Congratulations! You are a master angler!\n";
    } else if (fishingPoints >= 0) {
        std::cout << "Nice catch! You enjoy fishing.\n";
    } else {
        std::cout << "Better luck next time. Keep practicing!\n";
    }

    return 0;
}
