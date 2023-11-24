#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

// Function prototypes
int wordCounter(const char*);
double averageLetters(const char*);

// Overloaded function for string class
int wordCounter(const string&);
double averageLetters(const string&);

int main() {
    const int SIZE = 100;
    char userCString[SIZE];
    string userString;

    // Get a C-string from the user
    cout << "Enter a C-string: ";
    cin.getline(userCString, SIZE);

    // Call the functions for C-string and display the results
    int wordCountC = wordCounter(userCString);
    cout << "Number of words (C-string): " << wordCountC << endl;

    double avgLettersC = averageLetters(userCString);
    cout << "Average number of letters in each word (C-string): " << avgLettersC << endl;

    // Get a string from the user
    cout << "Enter a string: ";
    getline(cin, userString);

    // Call the overloaded functions for string class and display the results
    int wordCountString = wordCounter(userString);
    cout << "Number of words (string class): " << wordCountString << endl;

    double avgLettersString = averageLetters(userString);
    cout << "Average number of letters in each word (string class): " << avgLettersString << endl;

    return 0;
}

// Function to count the number of words in a C-string
int wordCounter(const char* str) {
    int count = 0;

    while (*str != '\0') {
        if (!isspace(*str) && (isspace(*(str + 1)) || *(str + 1) == '\0')) {
            count++;
        }

        str++;
    }

    return count;
}

// Function to calculate the average number of letters in each word in a C-string
double averageLetters(const char* str) {
    int totalLetters = 0;
    int wordCount = 0;

    while (*str != '\0') {
        if (isalpha(*str)) {
            totalLetters++;
        }

        if (!isspace(*str) && (isspace(*(str + 1)) || *(str + 1) == '\0')) {
            wordCount++;
        }

        str++;
    }

    return (wordCount == 0) ? 0.0 : static_cast<double>(totalLetters) / wordCount;
}

// Overloaded function to calculate the average number of letters in each word in a string class object
double averageLetters(const string& str) {
    int totalLetters = 0;
    int wordCount = 0;
    size_t pos = 0;

    while ((pos = str.find_first_of(" ", pos)) != string::npos) {
        wordCount++;
        pos = str.find_first_not_of(" ", pos);
    }

    wordCount++;

    return (wordCount == 0) ? 0.0 : static_cast<double>(totalLetters) / wordCount;
}
