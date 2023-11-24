#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int LINES_PER_PAGE = 24;

int main() {
    // Ask the user for the name of the file
    cout << "Enter the name of the file: ";
    string filename;
    getline(cin, filename);

    // Open the file
    ifstream file(filename);

    // Check if the file is open
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    // Display the contents of the file, pausing every 24 lines
    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        cout << line << endl;
        lineNumber++;

        if (lineNumber % LINES_PER_PAGE == 0) {
            cout << "Press Enter to continue...";
            cin.ignore(); // Wait for user to press Enter
        }
    }

    // Close the file
    file.close();

    return 0;
}
