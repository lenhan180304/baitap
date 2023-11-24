#include <iostream>
#include <cstring> // Required for C-string functions
#include <string>  // Required for string class
using namespace std;

// Function prototype for C-string
int wordCounter(const char*);

// Overloaded function for string class
int wordCounter(const string&);

int main() {
    const int SIZE = 100; // Maximum size of the C-string
    char userCString[SIZE];
    string userString;

    // Get a C-string from the user
    cout << "Enter a C-string: ";
    cin.getline(userCString, SIZE);

    // Call the function for C-string and display the result
    int wordCountC = wordCounter(userCString);
    cout << "Number of words (C-string): " << wordCountC << endl;

    // Get a string from the user
    cout << "Enter a string: ";
    getline(cin, userString);

    // Call the overloaded function for string class and display the result
    int wordCountString = wordCounter(userString);
    cout << "Number of words (string class): " << wordCountString << endl;

    return 0;
}

// Function to count the number of words in a C-string
int wordCounter(const char* str) {
    int count = 0;

    // Loop through the string
    while (*str != '\0') {
        // If the current character is not a space and the next character is a space or null character,
        // consider it as the end of a word
        if (!isspace(*str) && (isspace(*(str + 1)) || *(str + 1) == '\0')) {
            count++;
        }

        str++; // Move to the next character
    }

    return count;
}

// Overloaded function to count the number of words in a string class object
int wordCounter(const string& str) {
    int count = 0;
    size_t pos = 0;

    // Loop through the string using find_first_of
    while ((pos = str.find_first_of(" ", pos)) != string::npos) {
        count++;
        pos = str.find_first_not_of(" ", pos); // Move past the space
    }

    // Add one to the count for the last word
    count++;

    return count;
}
