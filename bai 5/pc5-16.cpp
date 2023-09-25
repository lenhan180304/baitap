#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double annualInterestRate, startingBalance;
    int months;

    cout << "Enter the annual interest rate (in decimal form): ";
    cin >> annualInterestRate;

    cout << "Enter the starting balance: $";
    cin >> startingBalance;

    cout << "Enter the number of months: ";
    cin >> months;

    double balance = startingBalance;
    double totalDeposits = 0.0;
    double totalWithdrawals = 0.0;
    double totalInterest = 0.0;

    for (int month = 1; month <= months; month++) {
        double deposit, withdrawal;
        
        cout << "\nMonth " << month << ":\n";
        
        // Ask for deposits and withdrawals
        cout << "Enter the amount deposited: $";
        cin >> deposit;
        while (deposit < 0) {
            cout << "Please enter a positive amount: $";
            cin >> deposit;
        }
        
        cout << "Enter the amount withdrawn: $";
        cin >> withdrawal;
        while (withdrawal < 0) {
            cout << "Please enter a positive amount: $";
            cin >> withdrawal;
        }

        // Update balance and totals
        balance += deposit - withdrawal;
        totalDeposits += deposit;
        totalWithdrawals += withdrawal;

        // Calculate monthly interest
        double monthlyInterest = (balance * annualInterestRate) / 12.0;
        balance += monthlyInterest;
        totalInterest += monthlyInterest;

        // Check for negative balance
        if (balance < 0) {
            cout << "Account closed due to a negative balance.\n";
            break;
        }
    }

    // Display the results
    cout << fixed << setprecision(2);
    cout << "\nEnding balance: $" << balance << endl;
    cout << "Total deposits: $" << totalDeposits << endl;
    cout << "Total withdrawals: $" << totalWithdrawals << endl;
    cout << "Total interest earned: $" << totalInterest << endl;

    return 0;
}

