#include <iostream>

using namespace std;

// Structure for hourly paid worker
struct HourlyPaid {
    double hoursWorked;
    double hourlyRate;
};

// Structure for salaried worker
struct Salaried {
    double salary;
    double bonus;
};

// Union with structures for both hourly paid and salaried workers
union PayrollData {
    HourlyPaid hourly;
    Salaried salaried;
};

int main() {
    PayrollData payroll; // Union variable to store data

    char workerType;

    cout << "Enter the type of worker (H for hourly paid, S for salaried): ";
    cin >> workerType;

    if (workerType == 'H' || workerType == 'h') {
        // Input data for hourly paid worker
        cout << "Enter hours worked: ";
        cin >> payroll.hourly.hoursWorked;

        // Input validation for hours worked
        while (payroll.hourly.hoursWorked < 0 || payroll.hourly.hoursWorked > 80) {
            cout << "Invalid input. Hours worked must be between 0 and 80. Please try again: ";
            cin >> payroll.hourly.hoursWorked;
        }

        cout << "Enter hourly rate: ";
        cin >> payroll.hourly.hourlyRate;

        // Input validation for hourly rate
        while (payroll.hourly.hourlyRate < 0) {
            cout << "Invalid input. Hourly rate cannot be negative. Please try again: ";
            cin >> payroll.hourly.hourlyRate;
        }

        // Calculate and display pay for hourly paid worker
        double pay = payroll.hourly.hoursWorked * payroll.hourly.hourlyRate;
        cout << "The pay for the hourly paid worker is: $" << pay << endl;

    } else if (workerType == 'S' || workerType == 's') {
        // Input data for salaried worker
        cout << "Enter salary: ";
        cin >> payroll.salaried.salary;

        // Input validation for salary
        while (payroll.salaried.salary < 0) {
            cout << "Invalid input. Salary cannot be negative. Please try again: ";
            cin >> payroll.salaried.salary;
        }

        cout << "Enter bonus: ";
        cin >> payroll.salaried.bonus;

        // Input validation for bonus
        while (payroll.salaried.bonus < 0) {
            cout << "Invalid input. Bonus cannot be negative. Please try again: ";
            cin >> payroll.salaried.bonus;
        }

        // Calculate and display pay for salaried worker
        double pay = payroll.salaried.salary + payroll.salaried.bonus;
        cout << "The pay for the salaried worker is: $" << pay << endl;

    } else {
        cout << "Invalid input. Please enter H for hourly paid or S for salaried worker." << endl;
    }

    return 0;
}
