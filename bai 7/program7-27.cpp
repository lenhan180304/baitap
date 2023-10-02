#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    vector<int> hours;      // Vector to store hours worked
    vector<double> payRate; // Vector to store hourly pay rates
    int numEmployees;       // Number of employees
    int index;              // Loop counter

    // Get the number of employees.
    cout << "How many employees do you have? ";
    cin >> numEmployees;

    // Input the payroll data.
    cout << "Enter the hours worked by " << numEmployees;
    cout << " employees and their hourly rates.\n";
    for (index = 0; index < numEmployees; index++)
    {
        int tempHours;    // Temporary variable to hold hours
        double tempRate;  // Temporary variable to hold pay rate

        cout << "Hours worked by employee #" << (index + 1) << ": ";
        cin >> tempHours;
        hours.push_back(tempHours); // Add hours to the vector

        cout << "Hourly pay rate for employee #" << (index + 1) << ": ";
        cin >> tempRate;
        payRate.push_back(tempRate); // Add pay rate to the vector
    }

    // Display each employee's gross pay.
    cout << "Here is the gross pay for each employee:\n";
    cout << fixed << showpoint << setprecision(2);
    for (index = 0; index < numEmployees; index++)
    {
        double grossPay = hours[index] * payRate[index];
        cout << "Employee #" << (index + 1) << ": $" << grossPay << endl;
    }

    return 0;
}
