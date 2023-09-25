// This program writes user input to a file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outputFile; // Declare an output file stream
    string name1, name2, name3;

    // Open an output file named "Friends.txt" for writing
    outputFile.open("Friends.txt");

    // Get the names of three friends
    cout << "Enter the names of three friends.\n";
    cout << "Friend #1: ";
    cin >> name1;
    cout << "Friend #2: ";
    cin >> name2;
    cout << "Friend #3: ";
    cin >> name3;

    // Write the names to the file, each on a separate line
    outputFile << name1 << endl;
    outputFile << name2 << endl;
    outputFile << name3 << endl;
    cout << "The names were saved to a file.\n";

    // Close the file
    outputFile.close();

    return 0;
}
