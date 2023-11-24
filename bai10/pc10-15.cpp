#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    // Open the file
    ifstream inputFile("text.txt");

    // Check if the file is opened successfully
    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    // Variables to count uppercase, lowercase, and digit characters
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int digitCount = 0;

    char ch;

    // Read characters from the file
    while (inputFile.get(ch)) {
        if (isupper(ch)) {
            uppercaseCount++;
        } else if (islower(ch)) {
            lowercaseCount++;
        } else if (isdigit(ch)) {
            digitCount++;
        }
    }

    // Close the file
    inputFile.close();

    // Display the results
    cout << "Number of uppercase letters: " << uppercaseCount << endl;
    cout << "Number of lowercase letters: " << lowercaseCount << endl;
    cout << "Number of digits: " << digitCount << endl;

    return 0;
}
