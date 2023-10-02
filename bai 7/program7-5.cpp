#include <iostream>
using namespace std;

int main() {
    const int SIZE = 3; // Constant for the array size
    int values[SIZE]; // An array of 3 integers
    int count; // Loop counter variable

    // Store three numbers in the three-element array.
    cout << "Storing 3 numbers in a 3-element array:\n";
    for (count = 0; count < SIZE; count++) {
        values[count] = 100 + count;
    }

    // Display the numbers.
    cout << "Here are the numbers:\n";
    for (count = 0; count < SIZE; count++) {
        cout << values[count] << endl;
    }
    
    return 0;
}
