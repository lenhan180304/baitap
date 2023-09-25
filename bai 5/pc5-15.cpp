#include <iostream>
using namespace std;

int main() {
    int employeeNumber;
    double grossPay, stateTax, federalTax, ficaWithholdings;
    double totalGrossPay = 0.0, totalStateTax = 0.0, totalFederalTax = 0.0, totalFicaWithholdings = 0.0, totalNetPay = 0.0;

    cout << "Payroll Report\n";
    cout << "Enter employee data or 0 to quit.\n\n";

    while (true) {
        cout << "Employee Number (0 to quit): ";
        cin >> employeeNumber;

        if (employeeNumber == 0) {
            break; // Exit the loop when 0 is entered
        }

        cout << "Gross Pay: $";
        cin >> grossPay;

        // Input validation
        if (grossPay < 0) {
            cout << "Gross Pay cannot be negative. Please reenter employee data.\n";
            continue; // Continue to the next iteration of the loop
        }

        cout << "State Tax: $";
        cin >> stateTax;

        cout << "Federal Tax: $";
        cin >> federalTax;

        cout << "FICA Withholdings: $";
        cin >> ficaWithholdings;

        if (stateTax < 0 || federalTax < 0 || ficaWithholdings < 0 || (stateTax + federalTax + ficaWithholdings) > grossPay) {
            cout << "Invalid tax or withholdings data. Please reenter employee data.\n";
            continue; // Continue to the next iteration of the loop
        }

        // Calculate net pay
        double netPay = grossPay - stateTax - federalTax - ficaWithholdings;

        // Accumulate totals
        totalGrossPay += grossPay;
        totalStateTax += stateTax;
        totalFederalTax += federalTax;
        totalFicaWithholdings += ficaWithholdings;
        totalNetPay += netPay;
    }

    cout << "\nPayroll Summary\n";
    cout << "Total Gross Pay: $" << totalGrossPay << endl;
    cout << "Total State Tax: $" << totalStateTax << endl;
    cout << "Total Federal Tax: $" << totalFederalTax << endl;
    cout << "Total FICA Withholdings: $" << totalFicaWithholdings << endl;
    cout << "Total Net Pay: $" << totalNetPay << endl;

    return 0;
}
