// main.cpp
#include <iostream>
#include "IntegerList.h"
using namespace std;

int main() {
    const int SIZE = 20;
    IntegerList numbers(SIZE);
    int val, x;

    // Store 9s in the list and display an asterisk
    // each time a 9 is successfully stored.
    for (x = 0; x < SIZE; x++) {
        numbers.setElement(x, 9);
        cout << "* ";
    }
    cout << endl;

    // Display the 9s.
    for (x = 0; x < SIZE; x++) {
        val = numbers.getElement(x);
        cout << val << " ";
    }
    cout << endl;

    // Attempt to store a value outside the list's bounds.
    numbers.setElement(50, 9);

    // This message will display only if the index is within bounds.
    cout << "Element 50 successfully set." << endl;

    return 0;
}
