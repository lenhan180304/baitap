#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(0)));

    int randomNumber = rand() % 100 + 1;  // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Welcome to the Random Number Guessing Game!\n";
    cout << "I've picked a number between 1 and 100. Try to guess it.\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < randomNumber) {
            cout << "Too low, try again.\n";
        } else if (guess > randomNumber) {
            cout << "Too high, try again.\n";
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        }
    } while (guess != randomNumber);

    return 0;
}
