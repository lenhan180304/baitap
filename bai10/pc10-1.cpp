#include <iostream>
#include <cstring> // Required for C-string functions
using namespace std;

// Function prototype
int countCharacters(const char*);

int main() {
    const int SIZE = 100; // Maximum size of the C-string
    char userString[SIZE];

    // Get a string from the user
    cout << "Enter a string: ";
    cin.getline(userString, SIZE);

    // Call the function to count characters and display the result
    int charCount = countCharacters(userString);
    cout << "Number of characters: " << charCount << endl;

    return 0;
}

// Function to count characters in a C-string
int countCharacters(const char* str) {
    int count = 0;

    // Loop until the null character is encountered
    while (*str != '\0') {
        count++;
        str++;
    }

    return count;
}
