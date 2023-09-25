#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double ASSESSMENT_PERCENTAGE = 0.6;
    const double SENIOR_HOMEOWNER_EXEMPTION = 5000.0;

    double actualValue, taxRate;

    // Ask the user for the actual value of the property and the tax rate
    cout << "Enter the actual value of the property: $";
    cin >> actualValue;
    cout << "Enter the current tax rate for each $100 of assessed value: $";
    cin >> taxRate;

    // Calculate the assessed value after applying the senior homeowner exemption
    double assessedValue = actualValue * ASSESSMENT_PERCENTAGE;
    assessedValue -= SENIOR_HOMEOWNER_EXEMPTION;

    // Calculate the annual property tax and quarterly tax bill
    double annualPropertyTax = assessedValue * (taxRate / 100.0);
    double quarterlyTaxBill = annualPropertyTax / 4.0;

    // Display the annual property tax and quarterly tax bill
    cout << "Annual Property Tax: $" << fixed << setprecision(2) << annualPropertyTax << endl;
    cout << "Quarterly Tax Bill: $" << fixed << setprecision(2) << quarterlyTaxBill << endl;

    return 0;
}
