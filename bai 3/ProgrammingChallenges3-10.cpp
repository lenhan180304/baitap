#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double replacementCost;

    // Ask the user for the replacement cost of the building
    cout << "Enter the replacement cost of the building: $";
    cin >> replacementCost;

    // Calculate the minimum amount of insurance to buy
    double minInsuranceAmount = 0.8 * replacementCost;

    // Display the minimum amount of insurance to buy
    cout << "Minimum amount of insurance to buy: $" << fixed << setprecision(2) << minInsuranceAmount << endl;

    return 0;
}
