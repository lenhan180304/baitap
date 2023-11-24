#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Function prototype
string separateWords(const string& input);

int main() {
    string inputSentence;

    // Get a sentence from the user
    cout << "Enter a sentence in CamelCase: ";
    getline(cin, inputSentence);

    // Convert and print the separated words
    cout << "Separated Words: " << separateWords(inputSentence) << endl;

    return 0;
}

// Function to separate words in CamelCase
string separateWords(const string& input) {
    string separatedWords;
    bool isFirstChar = true;

    for (char ch : input) {
        if (isupper(ch)) {
            if (!isFirstChar) {
                separatedWords += ' ';
            }
            separatedWords += tolower(ch);
            isFirstChar = false;
        } else {
            separatedWords += ch;
        }
    }

    return separatedWords;
}
