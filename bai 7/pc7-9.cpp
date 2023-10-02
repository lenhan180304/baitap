#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_EMPLOYEES = 7;

int main() {
    long empId[NUM_EMPLOYEES] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    int hours[NUM_EMPLOYEES];
    double payRate[NUM_EMPLOYEES];
    double wages[NUM_EMPLOYEES];

    cout << "Enter hours worked and hourly pay rate for each employee:\n";

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << "Employee " << empId[i] << ":\n";
        cout << "Hours worked: ";
        cin >> hours[i];

        // Input validation for hours (not negative)
        while (hours[i] < 0) {
            cout << "Please enter a non-negative value for hours worked: ";
            cin >> hours[i];
        }

        cout << "Hourly pay rate: $";
        cin >> payRate[i];

        // Input validation for pay rate (minimum $15.00)
        while (payRate[i] < 15.00) {
            cout << "Please enter a pay rate of at least $15.00: $";
            cin >> payRate[i];
        }

        wages[i] = hours[i] * payRate[i];
    }

    cout << "\nEmployee Gross Wages:\n";
    cout << "----------------------\n";

    cout << fixed << showpoint << setprecision(2);
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << "Employee ID: " << empId[i] << "\tGross Wages: $" << wages[i] << endl;
    }

    return 0;
}
