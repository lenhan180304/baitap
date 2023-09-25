#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double principal, interestRate;
    int timesCompounded;

    // Ask the user for the principal, interest rate, and times compounded
    cout << "Enter the principal: $";
    cin >> principal;
    cout << "Enter the interest rate: ";
    cin >> interestRate;
    cout << "Enter the number of times the interest is compounded: ";
    cin >> timesCompounded;

    // Calculate the interest
    double rate = interestRate / 100;
    double amount = principal * pow((1 + rate / timesCompounded), timesCompounded);
    double interest = amount - principal;

    // Display the report
    cout << fixed << setprecision(2);
    cout << "Interest Rate: " << interestRate << "%" << endl;
    cout << "Times Compounded: " << timesCompounded << endl;
    cout << "Principal: $" << principal << endl;
    cout << "Interest: $" << interest << endl;
    cout << "Amount in Savings: $" << amount << endl;

    return 0;
}
