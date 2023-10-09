#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getSales(double *, int);
double totalSales(double *, int);

int main()
{
    const int QTRS = 4;
    double sales[QTRS];

    // Get the sales data for all quarters.
    getSales(sales, QTRS);

    // Set the numeric output formatting.
    cout << fixed << showpoint << setprecision(2);

    // Display the total sales for the year.
    cout << "The total sales for the year are $";
    cout << totalSales(sales, QTRS) << endl;

    return 0;
}

// Definition of getSales function
// This function uses a pointer to accept the address of an array of doubles.
// The function asks the user to enter sales figures and stores them in the array.
void getSales(double *arr, int size)
{
    for (int count = 0; count < size; count++)
    {
        cout << "Enter the sales figure for quarter " << (count + 1) << ": ";
        cin >> arr[count];
    }
}

// Definition of totalSales function
// This function uses a pointer to accept the address of an array.
// The function returns the total of the elements in the array.
double totalSales(double *arr, int size)
{
    double sum = 0.0;

    for (int count = 0; count < size; count++)
    {
        sum += *arr; // Add the value pointed to by 'arr' to 'sum'
        arr++;       // Move the pointer to the next element
    }

    return sum;
}
