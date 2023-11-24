#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void displayFileTail(const string& filename, int linesToShow) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    vector<string> lines;
    string line;

    // Read all lines from the file
    while (getline(file, line)) {
        lines.push_back(line);
    }

    // Determine the starting index for displaying lines
    int startIndex = max(0, static_cast<int>(lines.size()) - linesToShow);

    // Display the lines
    for (int i = startIndex; i < lines.size(); ++i) {
        cout << lines[i] << endl;
    }

    file.close();
}

int main() {
    // File name
    string filename;

    // Get the file name from the user
    cout << "Enter the name of the file: ";
    getline(cin, filename);

    // Display the last 10 lines of the file
    cout << "\nFile Tail:\n";
    displayFileTail(filename, 10);

    return 0;
}
