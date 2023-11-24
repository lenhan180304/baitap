#include <iostream>
#include <cstdlib>
#include <ctime>

class Die {
public:
    Die();
    int roll();
private:
    int sides;
};

Die::Die() : sides(6) {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));
}

int Die::roll() {
    return rand() % sides + 1;
}

class GameOf21 {
public:
    GameOf21();
    void playGame();
private:
    Die die;
};

GameOf21::GameOf21() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));
}

void GameOf21::playGame() {
    int computerTotal = 0;
    int userTotal = 0;

    // Computer's turn
    computerTotal += die.roll();
    computerTotal += die.roll();
    std::cout << "Computer's total: " << computerTotal << std::endl;

    // Player's turn
    char rollAgain;
    do {
        int roll1 = die.roll();
        int roll2 = die.roll();
        userTotal += roll1 + roll2;

        std::cout << "You rolled: " << roll1 << " and " << roll2 << std::endl;
        std::cout << "Your total: " << userTotal << std::endl;

        if (userTotal > 21) {
            std::cout << "Bust! You went over 21. Computer wins!\n";
            return;
        }

        std::cout << "Do you want to roll again? (y/n): ";
        std::cin >> rollAgain;
    } while (rollAgain == 'y' || rollAgain == 'Y');

    // Determine the winner
    std::cout << "Computer's total: " << computerTotal << std::endl;
    if (computerTotal > 21 || (userTotal <= 21 && userTotal > computerTotal)) {
        std::cout << "Congratulations! You win!\n";
    } else {
        std::cout << "Computer wins!\n";
    }
}

int main() {
    GameOf21 game;
    game.playGame();

    return 0;
}
