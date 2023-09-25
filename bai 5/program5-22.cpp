// This program reads data from a file.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile; // Declare an input file stream
    int number;

    // Open the file named "ListOfNumbers.txt" for reading
    inputFile.open("Numbers.txt");

    // Read the numbers from the file and display them.
    while (inputFile >> number) {
        cout << number << endl;
    }

    // Close the file.
    inputFile.close();

    return 0;
}
