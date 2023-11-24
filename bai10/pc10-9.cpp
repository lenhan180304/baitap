#include <iostream>
#include <string>
using namespace std;

// Function prototype
char mostFrequentCharacter(const char*);
char mostFrequentCharacter(const string&);

int main() {
    const int SIZE = 100;
    char userCString[SIZE];
    string userString;

    // Get a C-string from the user
    cout << "Enter a C-string: ";
    cin.getline(userCString, SIZE);

    // Get a string object from the user
    cout << "Enter a string: ";
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, userString);

    // Find and display the most frequent character in the C-string
    cout << "Most frequent character in the C-string: " << mostFrequentCharacter(userCString) << endl;

    // Find and display the most frequent character in the string object
    cout << "Most frequent character in the string: " << mostFrequentCharacter(userString) << endl;

    return 0;
}

// Function to find the most frequent character in a C-string
char mostFrequentCharacter(const char* str) {
    int frequency[256] = {0}; // Assuming ASCII characters

    // Count the frequency of each character in the string
    while (*str != '\0') {
        frequency[static_cast<unsigned char>(*str)]++;
        str++;
    }

    // Find the character with the highest frequency
    char mostFrequentChar = '\0';
    int maxFrequency = 0;
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostFrequentChar = static_cast<char>(i);
        }
    }

    return mostFrequentChar;
}

// Function to find the most frequent character in a string object
char mostFrequentCharacter(const string& str) {
    return mostFrequentCharacter(str.c_str());
}
