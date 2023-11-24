#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void searchStringInFile(const string& filename, const string& targetString) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    int lineNumber = 0;
    int occurrences = 0;

    // Read each line and search for the target string
    while (getline(file, line)) {
        lineNumber++;

        size_t found = line.find(targetString);
        while (found != string::npos) {
            cout << "Found at line " << lineNumber << ", position " << found + 1 << ": " << line << endl;
            occurrences++;
            found = line.find(targetString, found + 1);
        }
    }

    file.close();

    // Report the number of occurrences
    if (occurrences > 0) {
        cout << "Total occurrences of '" << targetString << "': " << occurrences << endl;
    } else {
        cout << "String '" << targetString << "' not found in the file." << endl;
    }
}

int main() {
    // File name and string to search for
    string filename, targetString;

    // Get the file name and target string from the user
    cout << "Enter the name of the file: ";
    getline(cin, filename);

    cout << "Enter the string to search for: ";
    getline(cin, targetString);

    // Search for the string in the file
    searchStringInFile(filename, targetString);

    return 0;
}
