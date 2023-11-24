#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Function prototypes
int countVowels(const char*);
int countConsonants(const char*);

int main() {
    const int SIZE = 100;
    char userCString[SIZE];

    // Menu-driven program
    char choice;
    do {
        // Get a C-string from the user
        cout << "Enter a C-string: ";
        cin.ignore(); // Ignore newline character from previous input
        cin.getline(userCString, SIZE);

        // Display the menu
        cout << "\nMenu:\n";
        cout << "A) Count the number of vowels in the string\n";
        cout << "B) Count the number of consonants in the string\n";
        cout << "C) Count both the vowels and consonants in the string\n";
        cout << "D) Enter another string\n";
        cout << "E) Exit the program\n";
        cout << "Enter your choice (A/B/C/D/E): ";
        cin >> choice;

        // Perform the operation based on user's choice
        switch (choice) {
            case 'A':
                cout << "Number of vowels: " << countVowels(userCString) << endl;
                break;
            case 'B':
                cout << "Number of consonants: " << countConsonants(userCString) << endl;
                break;
            case 'C':
                cout << "Number of vowels: " << countVowels(userCString) << endl;
                cout << "Number of consonants: " << countConsonants(userCString) << endl;
                break;
            case 'D':
                // Continue to the next iteration to enter another string
                continue;
            case 'E':
                // Exit the program
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter A, B, C, D, or E.\n";
        }
    } while (choice != 'E');

    return 0;
}

// Function to count the number of vowels in a C-string
int countVowels(const char* str) {
    int count = 0;

    while (*str != '\0') {
        char currentChar = tolower(*str);
        if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u') {
            count++;
        }

        str++;
    }

    return count;
}

// Function to count the number of consonants in a C-string
int countConsonants(const char* str) {
    int count = 0;

    while (*str != '\0') {
        char currentChar = tolower(*str);
        if (isalpha(*str) && currentChar != 'a' && currentChar != 'e' && currentChar != 'i' && currentChar != 'o' && currentChar != 'u') {
            count++;
        }

        str++;
    }

    return count;
}
