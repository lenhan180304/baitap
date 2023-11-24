#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    const string fileName = "text.txt";

    ifstream inFile(fileName);

    if (!inFile.is_open()) {
        cerr << "Error: Unable to open the file for reading.\n";
        return 1;
    }

    string line;
    int totalWords = 0;
    int sentenceCount = 0;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string word;

        while (iss >> word) {
            totalWords++;
        }

        sentenceCount++;
    }

    inFile.close();

    if (sentenceCount == 0) {
        cerr << "Error: The file is empty.\n";
        return 1;
    }

    double averageWordsPerSentence = static_cast<double>(totalWords) / sentenceCount;

    cout << "Average number of words per sentence: " << averageWordsPerSentence << endl;

    return 0;
}
