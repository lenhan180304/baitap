// This program reads data from a file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile; // Declare an input file stream
    string name;

    inputFile.open("Friends.txt"); // Open the file "Friends.txt" for reading
    cout << "Reading data from the file.\n";

    inputFile >> name; // Read the first name from the file
    cout << name << endl; // Display the first name

    inputFile >> name; // Read the second name from the file
    cout << name << endl; // Display the second name

    inputFile >> name; // Read the third name from the file
    cout << name << endl; // Display the third name

    inputFile.close(); // Close the file

    return 0;
}
