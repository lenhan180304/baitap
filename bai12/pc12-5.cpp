#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayFileWithLineNumbers(const string& filename, int linesPerPage) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    int lineNumber = 0;
    string line;

    // Read and display lines with line numbers
    while (getline(file, line)) {
        cout << ++lineNumber << ":" << line << endl;

        // Pause after displaying linesPerPage lines
        if (lineNumber % linesPerPage == 0) {
            cout << "Press Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    file.close();
}

int main() {
    // File name
    string filename;

    // Get the file name from the user
    cout << "Enter the name of the file: ";
    getline(cin, filename);

    // Display the file with line numbers
    cout << "\nFile Contents with Line Numbers:\n";
    displayFileWithLineNumbers(filename, 24);

    return 0;
}
