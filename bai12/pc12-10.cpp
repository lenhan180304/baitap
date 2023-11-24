#include <iostream>
#include <fstream>

using namespace std;

void decryptFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error: Unable to open files for decryption." << endl;
        return;
    }

    char ch;

    while (inputFile.get(ch)) {
        // Reverse the encryption: Subtract 10 from the ASCII code of each character
        ch = static_cast<char>(ch - 10);

        // Write the decrypted character to the output file
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();

    cout << "File decrypted successfully." << endl;
}

int main() {
    string inputFileName, outputFileName;

    // Get input (coded) file name from the user
    cout << "Enter the name of the input (coded) file: ";
    cin >> inputFileName;

    // Get output (decrypted) file name from the user
    cout << "Enter the name of the output (decrypted) file: ";
    cin >> outputFileName;

    // Decrypt the file
    decryptFile(inputFileName, outputFileName);

    return 0;
}
