// This program tests for file open errors.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile; // Declare an input file stream
    int number;

    // Open the file "BadListOfNumbers.txt" for reading
    inputFile.open("Numbers.txt");

    // If the file successfully opened, process it.
    if (inputFile) {
        // Read the numbers from the file and display them.
        while (inputFile >> number) {
            cout << number << endl;
        }

        // Close the file.
        inputFile.close();
    } else {
        // Display an error message.
        cout << "Error opening the file.\n";
    }

    return 0;
}
