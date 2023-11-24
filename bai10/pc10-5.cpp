#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

// Function prototypes
void capitalizeSentences(char*);
void capitalizeSentences(string&);

// Overloaded function for string class
void capitalizeSentences(string&);

int main() {
    const int SIZE = 100;
    char userCString[SIZE];
    string userString;

    // Get a C-string from the user
    cout << "Enter a C-string: ";
    cin.getline(userCString, SIZE);

    // Call the function for C-string and display the modified string
    capitalizeSentences(userCString);
    cout << "Modified C-string: " << userCString << endl;

    // Get a string from the user
    cout << "Enter a string: ";
    getline(cin, userString);

    // Call the overloaded function for string class and display the modified string
    capitalizeSentences(userString);
    cout << "Modified string class: " << userString << endl;

    return 0;
}

// Function to capitalize the first character of each sentence in a C-string
void capitalizeSentences(char* str) {
    // Capitalize the first character of the string
    if (isalpha(*str)) {
        *str = toupper(*str);
    }

    // Loop through the string
    while (*str != '\0') {
        // If the current character is a period, exclamation mark, or question mark, and the next character is a space,
        // capitalize the character after the space
        if ((*str == '.' || *str == '!' || *str == '?') && *(str + 1) == ' ') {
            char nextChar = *(str + 2);
            if (isalpha(nextChar)) {
                *(str + 2) = toupper(nextChar);
            }
        }

        str++;
    }
}

// Overloaded function to capitalize the first character of each sentence in a string class object
void capitalizeSentences(string& str) {
    // Capitalize the first character of the string
    if (!str.empty() && isalpha(str[0])) {
        str[0] = toupper(str[0]);
    }

    // Loop through the string using find_first_of
    size_t pos = 0;
    while ((pos = str.find_first_of(".!? ", pos)) != string::npos) {
        // Move past the punctuation and space
        pos += 2;

        // Capitalize the character after the space
        if (pos < str.length() && isalpha(str[pos])) {
            str[pos] = toupper(str[pos]);
        }
    }
}
