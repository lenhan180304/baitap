#include <iostream>
using namespace std;

// Function prototypes
void getNumber(int *);   // Function to get a number from the user
void doubleValue(int *); // Function to double the value stored at an address

int main()
{
    int number; // Declare an integer variable

    // Call getNumber and pass the address of the 'number' variable
    getNumber(&number);

    // Call doubleValue and pass the address of the 'number' variable
    doubleValue(&number);

    // Display the value stored in 'number' after doubling
    cout << "That value doubled is " << number << endl;

    return 0;
}

// Definition of getNumber function
// The parameter 'input' is a pointer to an integer
// This function asks the user for a number and stores it in the variable pointed to by 'input'
void getNumber(int *input)
{
    cout << "Enter an integer number: ";
    cin >> *input; // Read a value from the user and store it in the address pointed to by 'input'
}

// Definition of doubleValue function
// The parameter 'val' is a pointer to an integer
// This function multiplies the value stored at the address pointed to by 'val' by two
void doubleValue(int *val)
{
    *val *= 2; // Double the value at the address pointed to by 'val'
}
