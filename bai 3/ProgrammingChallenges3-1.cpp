#include <iostream>
using namespace std;

int main()
{
    double gallons, miles, mileage;

    // Ask the user to enter the number of gallons of gas the car can hold
    cout << "Enter the number of gallons of gas the car can hold: ";
    cin >> gallons;

    // Ask the user to enter the number of miles the car can be driven on a full tank
    cout << "Enter the number of miles the car can be driven on a full tank: ";
    cin >> miles;

    // Calculate the mileage
    mileage = miles / gallons;

    // Display the mileage
    cout << "The number of miles that may be driven per gallon of gas is: " << mileage << endl;

    return 0;
}
