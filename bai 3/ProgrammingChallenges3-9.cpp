#include <iostream>
using namespace std;

int main()
{
    const int COOKIES_PER_BAG = 30;
    const int SERVINGS_PER_BAG = 10;
    const int CALORIES_PER_SERVING = 300;

    // Ask the user for the number of cookies eaten
    int numCookies;
    cout << "Enter the number of cookies eaten: ";
    cin >> numCookies;

    // Calculate the number of servings and total calories consumed
    int numServings = numCookies / (COOKIES_PER_BAG / SERVINGS_PER_BAG);
    int totalCalories = numServings * CALORIES_PER_SERVING;

    // Display the total calories consumed
    cout << "Total calories consumed: " << totalCalories << " calories" << endl;

    return 0;
}
