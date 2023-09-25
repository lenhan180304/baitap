#include <iostream>
using namespace std;

int main() {
    // Variable to store the number
    int number;
    
    // Ask the user to enter a number
    cout << "Enter a number within the range of 1 through 10: ";
    cin >> number;
    
    // Validate the input
    if (number < 1 || number > 10) {
        cout << "Invalid input. Number must be within the range of 1 through 10." << endl;
        return 0;
    }
    
    // Convert the number to Roman numeral using a switch statement
    string romanNumeral;
    switch(number) {
        case 1:
            romanNumeral = "I";
            break;
        case 2:
            romanNumeral = "II";
            break;
        case 3:
            romanNumeral = "III";
            break;
        case 4:
            romanNumeral = "IV";
            break;
        case 5:
            romanNumeral = "V";
            break;
        case 6:
            romanNumeral = "VI";
            break;
        case 7:
            romanNumeral = "VII";
            break;
        case 8:
            romanNumeral = "VIII";
            break;
        case 9:
            romanNumeral = "IX";
            break;
        case 10:
            romanNumeral = "X";
            break;
    }
    
    // Display the Roman numeral version of the number
    cout << "The Roman numeral version of the number is: " << romanNumeral << endl;

    return 0;
}
