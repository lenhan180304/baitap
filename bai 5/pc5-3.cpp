#include <iostream>
using namespace std;

int main() {
    const double RISE_PER_YEAR = 1.5; // Ocean level rise rate in millimeters per year
    int years = 25; // Number of years to calculate
    double totalRise = 0.0; // Accumulator for total rise

    // Display the table header
    cout << "Year\tOcean Rise (mm)" << endl;
    cout << "-----------------------" << endl;

    // Calculate and display the rise for each year
    for (int year = 1; year <= years; year++) {
        totalRise += RISE_PER_YEAR; // Accumulate the rise
        cout << year << "\t" << totalRise << endl;
    }

    return 0;
}
