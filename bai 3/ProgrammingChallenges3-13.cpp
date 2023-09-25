#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double YEN_PER_DOLLAR = 98.93;
    const double EUROS_PER_DOLLAR = 0.74;

    double dollarAmount;

    // Ask the user for the dollar amount
    cout << "Enter the dollar amount: $";
    cin >> dollarAmount;

    // Convert to Japanese yen and euros
    double yenAmount = dollarAmount * YEN_PER_DOLLAR;
    double euroAmount = dollarAmount * EUROS_PER_DOLLAR;

    // Display the converted amounts
    cout << "Amount in Japanese yen: " << fixed << setprecision(2) << yenAmount << endl;
    cout << "Amount in euros: " << fixed << setprecision(2) << euroAmount << endl;

    return 0;
}
