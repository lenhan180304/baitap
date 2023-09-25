#include <iostream>
using namespace std;

int main() {
    // Variables to store the numbers
    int num1, num2;

    // Ask the user to enter two numbers
    cout << "Enter the first number: ";
    cin >> num1;
    
    cout << "Enter the second number: ";
    cin >> num2;

    // Determine the smaller and larger numbers
    int smaller = (num1 < num2) ? num1 : num2;
    int larger = (num1 > num2) ? num1 : num2;

    // Display the result
    cout << "The smaller number is: " << smaller << endl;
    cout << "The larger number is: " << larger << endl;

    return 0;
}
