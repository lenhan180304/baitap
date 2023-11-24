#include <iostream>
using namespace std;

int main() {
    char again;

    do {
        // Display a string literal
        cout << "C++ programming is great fun!" << endl;

        // Ask the user if they want to see the message again
        cout << "Do you want to see the message again? ";
        cin >> again;
    } while (again == 'Y' || again == 'y');

    // Program ends if the user chooses not to see the message
    return 0;
}
