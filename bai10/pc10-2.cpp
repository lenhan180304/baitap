#include <iostream>
#include <cstring> // Required for C-string functions
using namespace std;

// Function prototype
void displayBackward(const char*);

int main() {
    const int SIZE = 100; // Maximum size of the C-string
    char userString[SIZE];

    // Get a string from the user
    cout << "Enter a string: ";
    cin.getline(userString, SIZE);

    // Call the function to display the string backward
    cout << "Backward string: ";
    displayBackward(userString);
    cout << endl;

    return 0;
}

// Function to display a C-string backward
void displayBackward(const char* str) {
    // Use recursion to display characters in reverse order
    if (*str != '\0') {
        displayBackward(str + 1);
        cout << *str;
    }
}
