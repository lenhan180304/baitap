#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayJoke(const string& filename) {
    ifstream jokeFile(filename);

    if (!jokeFile.is_open()) {
        cerr << "Error: Unable to open joke file." << endl;
        return;
    }

    string line;
    while (getline(jokeFile, line)) {
        cout << line << endl;
    }

    jokeFile.close();
}

void displayPunchLine(const string& filename) {
    ifstream punchLineFile(filename);

    if (!punchLineFile.is_open()) {
        cerr << "Error: Unable to open punch line file." << endl;
        return;
    }

    string line;
    streampos lastNewlinePos = 0;

    // Find the position of the last newline character
    while (getline(punchLineFile, line)) {
        lastNewlinePos = punchLineFile.tellg();
    }

    // Seek to the beginning of the last line
    punchLineFile.seekg(lastNewlinePos);

    // Display the punch line
    while (getline(punchLineFile, line)) {
        cout << line << endl;
    }

    punchLineFile.close();
}

int main() {
    // File names
    string jokeFilename = "joke.txt";
    string punchLineFilename = "punchline.txt";

    // Display the joke
    cout << "Joke:\n";
    displayJoke(jokeFilename);

    // Display the punch line
    cout << "\nPunch Line:\n";
    displayPunchLine(punchLineFilename);

    return 0;
}
