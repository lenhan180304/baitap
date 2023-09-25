#include <iostream>
using namespace std;

int main() {
    int speed, hours;

    // Get the speed of the vehicle (in miles per hour)
    cout << "What is the speed of the vehicle in mph? ";
    cin >> speed;

    // Input validation for non-negative speed
    while (speed < 0) {
        cout << "Please enter a non-negative speed: ";
        cin >> speed;
    }

    // Get the number of hours traveled
    cout << "How many hours has it traveled? ";
    cin >> hours;

    // Input validation for a minimum of 1 hour traveled
    while (hours < 1) {
        cout << "Please enter at least 1 hour of travel: ";
        cin >> hours;
    }

    // Display the table header
    cout << "Hour\tDistance Traveled\n";
    cout << "------------------------\n";

    // Calculate and display distance traveled for each hour
    for (int hour = 1; hour <= hours; hour++) {
        int distance = speed * hour;
        cout << hour << "\t" << distance << endl;
    }

    return 0;
}
