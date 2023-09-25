#include <iostream>
using namespace std;

int main() {
    int charCount = 0;

    // Loop through ASCII codes from 0 to 127
    for (int asciiCode = 0; asciiCode <= 127; asciiCode++) {
        // Display the character for the current ASCII code
        cout << static_cast<char>(asciiCode) << " ";

        // Increment the character count
        charCount++;

        // Start a new line after displaying 16 characters
        if (charCount == 16) {
            cout << endl;
            charCount = 0; // Reset the character count
        }
    }

    return 0;
}
