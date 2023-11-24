#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

// Function prototype
string formatDate(const string& date);

int main() {
    string inputDate;

    // Get a date from the user
    cout << "Enter a date in the format mm/dd/yyyy: ";
    cin >> inputDate;

    // Print the formatted date
    cout << "Formatted Date: " << formatDate(inputDate) << endl;

    return 0;
}

// Function to format the date
string formatDate(const string& date) {
    // Create a stringstream to parse the date
    stringstream ss(date);
    
    // Variables to store month, day, and year
    int month, day, year;

    // Extract month, day, and year from the input date
    char slash; // To handle the '/'
    ss >> month >> slash >> day >> slash >> year;

    // Array of month names
    string monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Format and return the date
    stringstream formattedDate;
    formattedDate << monthNames[month - 1] << " " << day << ", " << year;

    return formattedDate.str();
}
