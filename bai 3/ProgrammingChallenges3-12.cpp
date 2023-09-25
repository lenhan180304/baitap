#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double celsius;

    // Ask the user for the Celsius temperature
    cout << "Enter the temperature in Celsius: ";
    cin >> celsius;


    // Convert Celsius to Fahrenheit
    double fahrenheit = (celsius * 9 / 5) + 32;

    // Display the Fahrenheit temperature
    cout << "Temperature in Fahrenheit: " << fixed << setprecision(2) << fahrenheit << " F" << endl;

    return 0;
}
