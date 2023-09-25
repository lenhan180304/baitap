#include <iostream>
using namespace std;

int main() {
    const double CALORIES_PER_MINUTE = 3.6; // Calories burned per minute
    int minutes[] = {5, 10, 15, 20, 25, 30}; // Array of minutes
    int numMinutes = sizeof(minutes) / sizeof(minutes[0]); // Number of elements in the array

    // Display the table header
    cout << "Minutes\tCalories Burned" << endl;
    cout << "----------------------" << endl;

    // Calculate and display calories burned for each time interval
    for (int i = 0; i < numMinutes; i++) {
        int minutesRun = minutes[i];
        double caloriesBurned = CALORIES_PER_MINUTE * minutesRun;
        cout << minutesRun << "\t" << caloriesBurned << endl;
    }

    return 0;
}
