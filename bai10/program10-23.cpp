// This program lets the user enter a number. The
// dollarFormat function formats the number as
// a dollar amount.
#include <iostream>
#include <string>
using namespace std;

// Function prototype
void dollarFormat(string &);

int main() {
    string input;

    // Get the dollar amount from the user.
    cout << "Enter a dollar amount in the form nnnnn.nn : ";
    cin >> input;

    // Call the dollarFormat function to format the input.
    dollarFormat(input);

    // Display the formatted amount.
    cout << "Here is the amount formatted:\n";
    cout << input << endl;

    return 0;
}

// Definition of the dollarFormat function.
void dollarFormat(string &currency) {
    int dp;

    dp = currency.find('.'); // Find decimal point
    if (dp > 3) // Insert commas
    {
        for (int x = dp - 3; x > 0; x -= 3)
            currency.insert(x, ",");
    }
    currency.insert(0, "$"); // Insert dollar sign
}
