#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

void filterSentences(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return;
    }

    if (!outFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        inFile.close();
        return;
    }

    char ch;
    bool newSentence = true;

    while (inFile.get(ch)) {
        if (newSentence && isalpha(ch)) {
            outFile.put(toupper(ch));
            newSentence = false;
        } else {
            outFile.put(tolower(ch));
        }

        if (ch == '.') {
            newSentence = true;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Filtering completed. Revised content saved to " << outputFile << endl;
}

int main() {
    string inputFileName, outputFileName;

    // Get file names from the user
    cout << "Enter the name of the input file: ";
    getline(cin, inputFileName);

    cout << "Enter the name of the output file: ";
    getline(cin, outputFileName);

    // Apply the sentence filter
    filterSentences(inputFileName, outputFileName);

    return 0;
}
