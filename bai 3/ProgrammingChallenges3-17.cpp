#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Generate two random numbers between 0 and 999
    srand(time(0));
    int num1 = rand() % 1000;
    int num2 = rand() % 1000;

    // Display the two random numbers to be added
    cout << "Add the following numbers:" << endl;
    cout << num1 << endl;
    cout << num2 << endl;

    // Wait for the student to press a key to check the answer
    cout << "Press any key to check the answer...";
    cin.get();

    // Calculate and display the correct solution
    int sum = num1 + num2;
    cout << "Correct solution: " << sum << endl;

    return 0;
}
