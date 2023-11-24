#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Function prototypes
void upper(char*);
void lower(char*);
void reverse(char*);

int main() {
    const int SIZE = 100;
    char userString[SIZE];

    // Get a string from the user
    cout << "Enter a string: ";
    cin.getline(userString, SIZE);

    // Display the original string
    cout << "Original String: " << userString << endl;

    // Pass the string through the functions: reverse, lower, and upper
    reverse(userString);
    cout << "After Reverse: " << userString << endl;

    lower(userString);
    cout << "After Lowercase: " << userString << endl;

    upper(userString);
    cout << "After Uppercase: " << userString << endl;

    return 0;
}

// Function to convert each character in the string to uppercase
void upper(char* str) {
    while (*str != '\0') {
        *str = toupper(*str);
        str++;
    }
}

// Function to convert each character in the string to lowercase
void lower(char* str) {
    while (*str != '\0') {
        *str = tolower(*str);
        str++;
    }
}

// Function to toggle the case of each character in the string
void reverse(char* str) {
    while (*str != '\0') {
        if (isupper(*str)) {
            *str = tolower(*str);
        } else if (islower(*str)) {
            *str = toupper(*str);
        }
        str++;
    }
}
