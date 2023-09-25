#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int dvdCount = 1;  // DVD counter
    int numDVDs;       // Number of DVDs rented
    double total = 0.0; // Accumulator
    char current;       // Current release, Y or N

    // Get the number of DVDs.
    cout << "How many DVDs are being rented? ";
    cin >> numDVDs;

    // Determine the charges.
    do {
        if ((dvdCount % 3) == 0) {
            cout << "DVD #" << dvdCount << " is free!\n";
            dvdCount++; // Skip the free DVD and continue
            continue;   // Immediately start the next iteration
        }

        cout << "Is DVD #" << dvdCount;
        cout << " a current release? (Y/N) ";
        cin >> current;

        if (current == 'Y' || current == 'y')
            total += 3.50;
        else
            total += 2.50;

        dvdCount++;
    } while (dvdCount <= numDVDs);

    // Display the total.
    cout << fixed << showpoint << setprecision(2);
    cout << "The total is $" << total << endl;

    return 0;
}
