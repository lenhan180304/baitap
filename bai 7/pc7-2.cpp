#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int NUM_MONTHS = 12;
    double rainfall[NUM_MONTHS];
    string monthNames[NUM_MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    double totalRainfall = 0, highestRainfall = -1, lowestRainfall = -1;
    int highestMonth = 0, lowestMonth = 0;

    for (int i = 0; i < NUM_MONTHS; i++) {
        do {
            cout << "Enter rainfall for " << monthNames[i] << ": ";
            cin >> rainfall[i];
        } while (rainfall[i] < 0);

        totalRainfall += rainfall[i];
        
        if (highestRainfall == -1 || rainfall[i] > highestRainfall) {
            highestRainfall = rainfall[i];
            highestMonth = i;
        }
        
        if (lowestRainfall == -1 || rainfall[i] < lowestRainfall) {
            lowestRainfall = rainfall[i];
            lowestMonth = i;
        }
    }

    double averageRainfall = totalRainfall / NUM_MONTHS;

    cout << fixed << showpoint << setprecision(2);
    cout << "Total rainfall for the year: " << totalRainfall << " inches\n";
    cout << "Average monthly rainfall: " << averageRainfall << " inches\n";
    cout << "Month with the highest rainfall: " << monthNames[highestMonth] << " (" << highestRainfall << " inches)\n";
    cout << "Month with the lowest rainfall: " << monthNames[lowestMonth] << " (" << lowestRainfall << " inches)\n";

    return 0;
}
