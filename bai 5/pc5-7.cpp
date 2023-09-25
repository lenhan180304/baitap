#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numDays;

    // Get the number of days worked
    cout << "Enter the number of days worked: ";
    cin >> numDays;

    // Validate input
    if (numDays < 1) {
        cout << "Invalid input. Please enter a number greater than or equal to 1." << endl;
        return 1; // Exit with an error code
    }

    // Display the header
    cout << "Day\tSalary (in dollars)\n";
    cout << "------------------------\n";

    double totalPay = 0.0;
    double salary = 0.01; // Starting with one penny

    for (int day = 1; day <= numDays; day++) {
        totalPay += salary;
        cout << day << "\t$" << fixed << setprecision(2) << salary << endl;
        salary *= 2; // Double the salary for the next day
    }

    // Display the total pay
    cout << "Total pay: $" << fixed << setprecision(2) << totalPay << endl;

    return 0;
}
