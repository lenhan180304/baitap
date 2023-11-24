#include <iostream>
#include <iomanip>

using namespace std;

// Structure to store student data
struct Student {
    string name;
    int idNum;
    double* tests; // Pointer to an array of test scores
    double average; // Average test score
    char grade; // Course grade
};

// Function to get data for each student
void getStudentData(Student& s) {
    cout << "Enter student name: ";
    (cin, s.name);
    cout << "Enter student ID number: ";
    cin >> s.idNum;
    // Input validation for ID number
    while (s.idNum <= 0) {
        cout << "ID number must be greater than 0. Enter a valid ID number: ";
        cin >> s.idNum;
    }
    cin.ignore(); // Consume the newline character left by cin
}

// Function to calculate average test score
void calculateAverage(Student& s, int numTests) {
    double sum = 0.0;
    for (int i = 0; i < numTests; ++i) {
        sum += s.tests[i];
    }
    s.average = sum / numTests;
}

// Function to calculate course grade based on average test score
void calculateGrade(Student& s) {
    if (s.average >= 91 && s.average <= 100) {
        s.grade = 'A';
    } else if (s.average >= 81 && s.average <= 90) {
        s.grade = 'B';
    } else if (s.average >= 71 && s.average <= 80) {
        s.grade = 'C';
    } else if (s.average >= 61 && s.average <= 70) {
        s.grade = 'D';
    } else {
        s.grade = 'F';
    }
}

// Function to display student information
void displayStudentInfo(const Student& s) {
    cout << setw(15) << left << s.name
         << setw(10) << s.idNum
         << setw(15) << fixed << setprecision(2) << s.average
         << setw(5) << s.grade
         << endl;
}

int main() {
    int numStudents, numTests;

    cout << "Enter the number of students: ";
    cin >> numStudents;
    // Input validation for the number of students
    while (numStudents <= 0) {
        cout << "Number of students must be greater than 0. Enter a valid number: ";
        cin >> numStudents;
    }

    cout << "Enter the number of tests: ";
    cin >> numTests;
    // Input validation for the number of tests
    while (numTests <= 0) {
        cout << "Number of tests must be greater than 0. Enter a valid number: ";
        cin >> numTests;
    }

    cin.ignore(); // Consume the newline character left by cin

    // Dynamically allocate an array of structures
    Student* students = new Student[numStudents];

    // Get data for each student
    for (int i = 0; i < numStudents; ++i) {
        students[i].tests = new double[numTests];
        getStudentData(students[i]);
        for (int j = 0; j < numTests; ++j) {
            cout << "Enter test score " << j + 1 << " for " << students[i].name << ": ";
            cin >> students[i].tests[j];
            // Input validation for test scores
            while (students[i].tests[j] < 0) {
                cout << "Test score cannot be negative. Enter a valid score: ";
                cin >> students[i].tests[j];
            }
        }
        calculateAverage(students[i], numTests);
        calculateGrade(students[i]);
    }

    // Display table header
    cout << setw(15) << left << "Name"
         << setw(10) << "ID"
         << setw(15) << "Average"
         << setw(5) << "Grade"
         << endl;
    
    // Display student information
    for (int i = 0; i < numStudents; ++i) {
        displayStudentInfo(students[i]);
    }

    // Deallocate dynamically allocated memory
    for (int i = 0; i < numStudents; ++i) {
        delete[] students[i].tests;
    }
    delete[] students;

    return 0;
}
