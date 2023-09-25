#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string month1, month2, month3;
    double rainfall1, rainfall2, rainfall3;
    double average;

    // Ask the user to enter the name and rainfall for each month
    cout << "Enter the name of the first month: ";
    getline(cin, month1);
    cout << "Enter the amount of rainfall (in inches) for " << month1 << ": ";
    cin >> rainfall1;

    cin.ignore(); // Ignore the newline character

    cout << "Enter the name of the second month: ";
    getline(cin, month2);
    cout << "Enter the amount of rainfall (in inches) for " << month2 << ": ";
    cin >> rainfall2;

    cin.ignore(); // Ignore the newline character

    cout << "Enter the name of the third month: ";
    getline(cin, month3);
    cout << "Enter the amount of rainfall (in inches) for " << month3 << ": ";
    cin >> rainfall3;

    // Calculate the average rainfall for three months
    average = (rainfall1 + rainfall2 + rainfall3) / 3.0;

    // Display the average rainfall
    cout << fixed << setprecision(2);
    cout << "The average rainfall for " << month1 << ", " << month2 << ", and " << month3 << " is " << average << " inches." << endl;

    return 0;
}
