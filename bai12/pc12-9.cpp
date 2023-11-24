#include <iostream>
#include <fstream>

using namespace std;

void encryptFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error: Unable to open files for encryption." << endl;
        return;
    }

    char ch;

    while (inputFile.get(ch)) {
        // Simple encryption: Add 10 to the ASCII code of each character
        ch = static_cast<char>(ch + 10);

        // Write the encrypted character to the output file
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();

    cout << "File encrypted successfully." << endl;
}

int main() {
    string inputFileName, outputFileName;

    // Get input file name from the user
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;

    // Get output file name from the user
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;

    // Encrypt the file
    encryptFile(inputFileName, outputFileName);

    return 0;
}
