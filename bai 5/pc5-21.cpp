#include <iostream>
#include <cstdlib> // For rand and srand functions
#include <ctime>   // For the time function
using namespace std;

int main()
{
    srand(time(0)); // Seed the random number generator with the current time
    int randomNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int userGuess;
    int guessCount = 0; // Initialize guess count

    cout << "Welcome to the Random Number Guessing Game!" << endl;
    cout << "I've picked a number between 1 and 100. Try to guess it." << endl;

    do
    {
        cout << "Enter your guess: ";
        cin >> userGuess;
        guessCount++; // Increment guess count

        if (userGuess < randomNumber)
        {
            cout << "Too low, try again." << endl;
        }
        else if (userGuess > randomNumber)
        {
            cout << "Too high, try again." << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the number in " << guessCount << " attempts." << endl;
        }
    } while (userGuess != randomNumber);

    return 0;
}
