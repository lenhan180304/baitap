#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE];
    int count;
    ofstream outputFile;

    // Populate the array with values.
    for (count = 0; count < ARRAY_SIZE; count++) {
        numbers[count] = count;
    }

    // Open the file for output.
    outputFile.open("SavedNumbers.txt");

    // Write the array contents to the file.
    for (count = 0; count < ARRAY_SIZE; count++) {
        outputFile << numbers[count] << endl;
    }

    // Close the file.
    outputFile.close();

    // Notify the user that the numbers were saved to the file.
    cout << "The numbers were saved to the file." << endl;
    return 0;
}
