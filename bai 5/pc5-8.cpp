#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int choice;

    // Seed the random number generator
    srand(time(0));

    do {
        // Display the menu
        cout << "Math Tutor Menu\n";
        cout << "1. Addition Problem\n";
        cout << "2. Subtraction Problem\n";
        cout << "3. Multiplication Problem\n";
        cout << "4. Division Problem\n";
        cout << "5. Quit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Handle menu selection
        switch (choice) {
            case 1: {
                // Addition Problem
                int num1 = rand() % 100;
                int num2 = rand() % 100;
                int answer, userAnswer;

                answer = num1 + num2;

                cout << "What is " << num1 << " + " << num2 << "? ";
                cin >> userAnswer;

                if (userAnswer == answer) {
                    cout << "Correct! Good job.\n";
                } else {
                    cout << "Sorry, the correct answer is " << answer << ".\n";
                }

                break;
            }
            case 2: {
                // Subtraction Problem
                int num1 = rand() % 100;
                int num2 = rand() % 100;
                int answer, userAnswer;

                answer = num1 - num2;

                cout << "What is " << num1 << " - " << num2 << "? ";
                cin >> userAnswer;

                if (userAnswer == answer) {
                    cout << "Correct! Good job.\n";
                } else {
                    cout << "Sorry, the correct answer is " << answer << ".\n";
                }

                break;
            }
            case 3: {
                // Multiplication Problem
                int num1 = rand() % 10;
                int num2 = rand() % 10;
                int answer, userAnswer;

                answer = num1 * num2;

                cout << "What is " << num1 << " * " << num2 << "? ";
                cin >> userAnswer;

                if (userAnswer == answer) {
                    cout << "Correct! Good job.\n";
                } else {
                    cout << "Sorry, the correct answer is " << answer << ".\n";
                }

                break;
            }
            case 4: {
                // Division Problem
                int num1 = rand() % 10 + 1;  // Ensure num1 is not zero
                int num2 = rand() % 10 + 1;  // Ensure num2 is not zero
                double answer, userAnswer;

                answer = static_cast<double>(num1) / num2;

                cout << "What is " << num1 << " / " << num2 << "? ";
                cin >> userAnswer;

                if (userAnswer == answer) {
                    cout << "Correct! Good job.\n";
                } else {
                    cout << "Sorry, the correct answer is " << answer << ".\n";
                }

                break;
            }
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
