#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double *sales = nullptr; // To dynamically allocate an array
    double total = 0.0;     // Accumulator
    double average;         // To hold average sales
    int numDays;            // To hold the number of days of sales
    int count;              // Counter variable

    // Get the number of days of sales.
    cout << "How many days of sales figures do you wish to process? ";
    cin >> numDays;

    // Dynamically allocate an array large enough to hold that many days of sales amounts.
    sales = new double[numDays];

    // Get the sales figures for each day.
    cout << "Enter the sales figures below.\n";
    for (count = 0; count < numDays; count++)
    {
        cout << "Day " << (count + 1) << ": ";
        cin >> sales[count];
    }

    // Calculate the total sales
    for (count = 0; count < numDays; count++)
    {
        total += sales[count];
    }

    // Calculate the average sales per day
    average = total / numDays;

    // Display the results
    cout << fixed << showpoint << setprecision(2);
    cout << "\n\nTotal Sales: $" << total << endl;
    cout << "Average Sales: $" << average << endl;

    // Free dynamically allocated memory
    delete[] sales;
    sales = nullptr; // Make sales a null pointer.

    return 0;
}
