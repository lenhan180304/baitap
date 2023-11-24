#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

int main() {
    const double PI = 3.14159; // Constant for pi
    double radius; // The circle's radius
    char goAgain; // To hold Y or N

    cout << "This program calculates the area of a circle.\n";
    cout << fixed << setprecision(2);

    do {
        // Prompt the user to enter the circle's radius
        cout << "Enter the circle's radius: ";
        cin >> radius;

        // Calculate and display the area of the circle
        cout << "The area is " << (PI * radius * radius);
        cout << endl;

        // Ask the user if they want to calculate another area
        cout << "Calculate another? (Y or N) ";
        cin >> goAgain;

        // Validate the input for 'Y' or 'N', case-insensitive
        while (toupper(goAgain) != 'Y' && toupper(goAgain) != 'N') {
            cout << "Please enter Y or N: ";
            cin >> goAgain;
        }

    } while (toupper(goAgain) == 'Y');

    // Program ends if the user chooses 'N' or 'n'
    return 0;
}
