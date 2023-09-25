#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int COOKIES_PER_RECIPE = 48;
    const double SUGAR_PER_RECIPE = 1.5;
    const double BUTTER_PER_RECIPE = 1.0;
    const double FLOUR_PER_RECIPE = 2.75;

    // Get the number of cookies to make from the user
    int numCookies;
    cout << "Enter the number of cookies you want to make: ";
    cin >> numCookies;

    // Calculate the ingredient amounts based on the number of cookies
    double sugarAmount = (numCookies / static_cast<double>(COOKIES_PER_RECIPE)) * SUGAR_PER_RECIPE;
    double butterAmount = (numCookies / static_cast<double>(COOKIES_PER_RECIPE)) * BUTTER_PER_RECIPE;
    double flourAmount = (numCookies / static_cast<double>(COOKIES_PER_RECIPE)) * FLOUR_PER_RECIPE;

    // Display the ingredient amounts needed
    cout << fixed << setprecision(2);
    cout << "For " << numCookies << " cookies, you will need:" << endl;
    cout << sugarAmount << " cups of sugar" << endl;
    cout << butterAmount << " cups of butter" << endl;
    cout << flourAmount << " cups of flour" << endl;

    return 0;
}
