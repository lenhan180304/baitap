#include <iostream>
#include <cctype>
using namespace std;

// Function prototypes
bool isPasswordValid(const string& password);

int main() {
    string password;

    // Get a password from the user
    cout << "Enter your password: ";
    cin >> password;

    // Check if the password is valid
    if (isPasswordValid(password)) {
        cout << "Password is valid. Welcome!" << endl;
    } else {
        cout << "Invalid password. Please follow the password criteria." << endl;
    }

    return 0;
}

// Function to check if the password meets the criteria
bool isPasswordValid(const string& password) {
    // Check the length
    if (password.length() < 6) {
        cout << "Password should be at least six characters long." << endl;
        return false;
    }

    // Check for at least one uppercase and one lowercase letter
    bool hasUppercase = false;
    bool hasLowercase = false;

    for (char ch : password) {
        if (isupper(ch)) {
            hasUppercase = true;
        } else if (islower(ch)) {
            hasLowercase = true;
        }
    }

    if (!hasUppercase || !hasLowercase) {
        cout << "Password should contain at least one uppercase and one lowercase letter." << endl;
        return false;
    }

    // Check for at least one digit
    bool hasDigit = false;

    for (char ch : password) {
        if (isdigit(ch)) {
            hasDigit = true;
            break;
        }
    }

    if (!hasDigit) {
        cout << "Password should have at least one digit." << endl;
        return false;
    }

    // If all criteria are met
    return true;
}
