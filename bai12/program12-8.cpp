 #include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string input;         // To hold file input
    ifstream nameFile;    // File stream object

    // Open the file in input mode.
    nameFile.open("murphy.txt", ios::in);

    // If the file was successfully opened, continue.
    if (nameFile) {
        // Read and display each line from the file.
        while (getline(nameFile, input)) {
            cout << input << endl;
        }

        // Close the file.
        nameFile.close();
    } else {
        cout << "ERROR: Cannot open file.\n";
    }

    return 0;
}
