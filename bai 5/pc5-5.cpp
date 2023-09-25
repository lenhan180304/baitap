#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double INITIAL_FEE = 2500.0; // Initial membership fee in dollars
    const double INCREASE_RATE = 0.04; // Annual increase rate (4%)
    int years = 6; // Number of years to project

    // Display the table header
    cout << "Year\tMembership Fee" << endl;
    cout << "-------------------" << endl;

    double membershipFee = INITIAL_FEE;

    // Calculate and display projected fees for each year
    for (int year = 1; year <= years; year++) {
        cout << year << "\t$" << fixed << setprecision(2) << membershipFee << endl;
        membershipFee += membershipFee * INCREASE_RATE; // Calculate the new fee for the next year
    }

    return 0;
}
