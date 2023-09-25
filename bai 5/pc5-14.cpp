#include <iostream>
#include <string>
using namespace std;

int main() {
    int numStudents;

    cout << "Enter the number of students in the class (1-25): ";
    cin >> numStudents;

    // Input validation
    if (numStudents < 1 || numStudents > 25) {
        cout << "Invalid number of students. Please enter a number between 1 and 25." << endl;
        return 1; // Exit with an error code
    }

    string firstName, firstStudent, lastStudent;

    for (int i = 1; i <= numStudents; i++) {
        cout << "Enter the name of student " << i << ": ";
        cin >> firstName;

        if (i == 1) {
            firstStudent = lastStudent = firstName;
        } else {
            if (firstName < firstStudent) {
                firstStudent = firstName;
            }
            if (firstName > lastStudent) {
                lastStudent = firstName;
            }
        }
    }

    cout << "The student at the front of the line is: " << firstStudent << endl;
    cout << "The student at the end of the line is: " << lastStudent << endl;

    return 0;
}
