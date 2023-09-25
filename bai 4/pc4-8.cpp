#include <iostream>
#include <string>
using namespace std;

int main() {
    // Variables to store the input colors
    string color1, color2;

    // Ask the user to enter the names of two primary colors
    cout << "Enter the name of the first primary color: ";
    cin >> color1;

    cout << "Enter the name of the second primary color: ";
    cin >> color2;

    // Determine the resulting secondary color
    string secondaryColor;
    if ((color1 == "red" && color2 == "blue") || (color1 == "blue" && color2 == "red")) {
        secondaryColor = "purple";
    } else if ((color1 == "red" && color2 == "yellow") || (color1 == "yellow" && color2 == "red")) {
        secondaryColor = "orange";
    } else if ((color1 == "blue" && color2 == "yellow") || (color1 == "yellow" && color2 == "blue")) {
        secondaryColor = "green";
    } else {
        cout << "Error: Invalid input. Please enter valid primary colors (red, blue, or yellow)." << endl;
        return 1; // Exit the program with an error status
    }

    // Display the resulting secondary color
    cout << "The resulting secondary color is: " << secondaryColor << endl;

    return 0;
}
