#include <iostream>
using namespace std;

int main() {
    // Variables to store the length and width of the rectangles
    double length1, width1, length2, width2;

    // Ask the user for the length and width of the first rectangle
    cout << "Enter the length of the first rectangle: ";
    cin >> length1;

    cout << "Enter the width of the first rectangle: ";
    cin >> width1;

    // Ask the user for the length and width of the second rectangle
    cout << "Enter the length of the second rectangle: ";
    cin >> length2;

    cout << "Enter the width of the second rectangle: ";
    cin >> width2;

    // Calculate the areas of the two rectangles
    double area1 = length1 * width1;
    double area2 = length2 * width2;

    // Compare the areas of the two rectangles and display the result
    if (area1 > area2) {
        cout << "The first rectangle has the greater area." << endl;
    } else if (area2 > area1) {
        cout << "The second rectangle has the greater area." << endl;
    } else {
        cout << "The areas of the rectangles are the same." << endl;
    }

    return 0;
}
