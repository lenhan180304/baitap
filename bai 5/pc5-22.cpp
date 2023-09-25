#include <iostream>
using namespace std;

int main() {
    int sideLength;

    // Ask the user for a positive integer (no greater than 15).
    cout << "Enter a positive integer no greater than 15: ";
    cin >> sideLength;

    // Validate input range.
    if (sideLength < 1 || sideLength > 15) {
        cout << "Invalid input. Please enter a positive integer between 1 and 15.\n";
        return 1;  // Exit the program with an error code.
    }

    // Display the square using 'X' characters.
    for (int row = 0; row < sideLength; row++) {
        for (int col = 0; col < sideLength; col++) {
            cout << "X";
        }
        cout << endl;
    }

    return 0;
}
