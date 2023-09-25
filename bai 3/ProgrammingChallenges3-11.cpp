#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double loanPayment, insurance, gas, oil, tires, maintenance;

    // Ask the user for the monthly costs of operating the automobile
    cout << "Enter the monthly loan payment: $";
    cin >> loanPayment;
    cout << "Enter the monthly insurance cost: $";
    cin >> insurance;
    cout << "Enter the monthly gas cost: $";
    cin >> gas;
    cout << "Enter the monthly oil cost: $";
    cin >> oil;
    cout << "Enter the monthly tires cost: $";
    cin >> tires;
    cout << "Enter the monthly maintenance cost: $";
    cin >> maintenance;

    // Calculate the total monthly and annual costs
    double totalMonthlyCost = loanPayment + insurance + gas + oil + tires + maintenance;
    double totalAnnualCost = totalMonthlyCost * 12;

    // Display the total monthly and annual costs
    cout << "Total monthly cost: $" << fixed << setprecision(2) << totalMonthlyCost << endl;
    cout << "Total annual cost: $" << fixed << setprecision(2) << totalAnnualCost << endl;

    return 0;
}
