#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int numbers[SIZE];

    // Input 10 values into the array
    cout << "Enter 10 integer values, one at a time:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Value " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Find the largest and smallest values
    int largest = numbers[0];
    int smallest = numbers[0];

    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }

    // Display the results
    cout << "The largest value is: " << largest << endl;
    cout << "The smallest value is: " << smallest << endl;

    return 0;
}
