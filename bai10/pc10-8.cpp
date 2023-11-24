#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string userInput;

    // Get a series of single-digit numbers from the user
    cout << "Enter a series of single-digit numbers with no separators: ";
    cin >> userInput;

    int sum = 0;
    char highestDigit = '0';
    char lowestDigit = '9';

    // Loop through each character in the string
    for (char digit : userInput) {
        if (isdigit(digit)) {
            // Convert the character to its integer equivalent and update the sum
            int num = digit - '0';
            sum += num;

            // Update the highest and lowest digits
            if (digit > highestDigit) {
                highestDigit = digit;
            }
            if (digit < lowestDigit) {
                lowestDigit = digit;
            }
        } else {
            // Ignore non-digit characters
            cout << "Ignoring non-digit character: " << digit << endl;
        }
    }

    // Display the results
    cout << "Sum of single-digit numbers: " << sum << endl;
    cout << "Highest digit: " << highestDigit << endl;
    cout << "Lowest digit: " << lowestDigit << endl;

    return 0;
}
