#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string month;
    int year;
    double totalCollected;

    // Ask the user for the month, year, and total amount collected
    cout << "Enter the month: ";
    cin >> month;
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the total amount collected: $";
    cin >> totalCollected;

    // Calculate the sales, county sales tax, state sales tax, and total sales tax
    double sales = totalCollected / 1.06;
    double countySalesTax = sales * 0.02;
    double stateSalesTax = sales * 0.04;
    double totalSalesTax = countySalesTax + stateSalesTax;

    // Display the sales tax report
    cout << "\nSales Tax Report" << endl;
    cout << "Month: " << month << " " << year << endl;
    cout << "------------------------" << endl;
    cout << "Total Collected: $" << fixed << setprecision(2) << totalCollected << endl;
    cout << "Sales: $" << fixed << setprecision(2) << sales << endl;
    cout << "County Sales Tax: $" << fixed << setprecision(2) << countySalesTax << endl;
    cout << "State Sales Tax: $" << fixed << setprecision(2) << stateSalesTax << endl;
    cout << "Total Sales Tax: $" << fixed << setprecision(2) << totalSalesTax << endl;

    return 0;
}
