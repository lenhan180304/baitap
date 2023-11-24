#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 4;
const char FILE_NAME[] = "test.dat";

int main() {
    char data[SIZE] = {'A', 'B', 'C', 'D'};
    fstream file;

    // Open the file for output in binary mode.
    file.open(FILE_NAME, ios::out | ios::binary);

    // Check if the file opened successfully.
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    // Write the contents of the array to the file.
    cout << "Writing the characters to the file.\n";
    file.write(data, sizeof(data));

    // Close the file.
    file.close();

    // Open the file for input in binary mode.
    file.open(FILE_NAME, ios::in | ios::binary);

    // Check if the file opened successfully.
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    // Read the contents of the file into the array.
    cout << "Now reading the data back into memory.\n";
    file.read(data, sizeof(data));

    // Display the contents of the array.
    for (int count = 0; count < SIZE; count++)
        cout << data[count] << " ";
    cout << endl;

    // Close the file.
    file.close();

    return 0;
}
