#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

    // Display the first 10 lines of the file
    string line;
    int lineNumber = 0;

    while (getline(file, line) && lineNumber < 10) {
        cout << line << endl;
        lineNumber++;
    }

    // Check if the file has fewer than 10 lines
    if (lineNumber < 10) {
        cout << "The entire file has been displayed." << endl;
    }

    // Close the file
    file.close();

    return 0;
}
