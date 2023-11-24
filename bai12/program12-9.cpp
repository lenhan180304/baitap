#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string input;          // To hold file input
    ifstream dataFile("names2.txt", ios::in);

    // If the file was successfully opened, continue.
    if (dataFile) {
        // Read and display each item using $ as a delimiter.
        while (getline(dataFile, input, '$')) {
            cout << input << endl;
        }

        // Close the file.
        dataFile.close();
    } else {
        cout << "ERROR: Cannot open file.\n";
    }

    return 0;
}
