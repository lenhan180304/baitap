#include <iostream>
using namespace std;

const int SIZE = 3;

// Function to check if a 2D array is a Lo Shu Magic Square
bool isLoShuMagicSquare(int square[][SIZE]) {
    int expectedSum = 15; // Sum of each row, column, and diagonal

    // Check each row and column
    for (int i = 0; i < SIZE; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < SIZE; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != expectedSum || colSum != expectedSum) {
            return false;
        }
    }

    // Check diagonals
    int diag1Sum = 0, diag2Sum = 0;
    for (int i = 0; i < SIZE; i++) {
        diag1Sum += square[i][i];
        diag2Sum += square[i][SIZE - i - 1];
    }

    return diag1Sum == expectedSum && diag2Sum == expectedSum;
}

int main() {
    int square[SIZE][SIZE];

    cout << "Enter a 3x3 square of numbers (1-9):\n";

    // Input values into the 2D array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> square[i][j];
        }
    }

    // Check if it's a Lo Shu Magic Square
    if (isLoShuMagicSquare(square)) {
        cout << "It's a Lo Shu Magic Square!\n";
    } else {
        cout << "It's not a Lo Shu Magic Square.\n";
    }

    return 0;
}
