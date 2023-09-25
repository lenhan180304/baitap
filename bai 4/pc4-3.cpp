#include <iostream>
using namespace std;

int main() {
    // Variables to store the month, day, and year
    int month, day, year;

    // Ask the user to enter a month, day, and two-digit year
    cout << "Enter a month (in numeric form): ";
    cin >> month;

    cout << "Enter a day: ";
    cin >> day;

    cout << "Enter a two-digit year: ";
    cin >> year;

    // Calculate the product of the month and day
    int product = month * day;

    // Check if the product is equal to the year
    if (product == year) {
        cout << "The date is magic!" << endl;
    } else {
        cout << "The date is not magic." << endl;
    }

    return 0;
}
