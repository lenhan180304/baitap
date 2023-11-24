#include <iostream>
#include <fstream>

using namespace std;

void arrayToFile(const string& fileName, const int* arr, int size) {
    ofstream outFile(fileName, ios::binary);

    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(arr), size * sizeof(int));

    outFile.close();
}

void fileToArray(const string& fileName, int* arr, int size) {
    ifstream inFile(fileName, ios::binary);

    if (!inFile.is_open()) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    inFile.read(reinterpret_cast<char*>(arr), size * sizeof(int));

    inFile.close();
}

int main() {
    const int arrSize = 5;
    int originalArray[arrSize] = {1, 2, 3, 4, 5};
    int loadedArray[arrSize] = {0}; // Initialize to zeros

    // Write array to file
    arrayToFile("arrayData.dat", originalArray, arrSize);

    // Read array from file
    fileToArray("arrayData.dat", loadedArray, arrSize);

    // Display the loaded array
    cout << "Loaded array from file: ";
    for (int i = 0; i < arrSize; ++i) {
        cout << loadedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
