#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("LineUp.txt");

    if (!inputFile) {
        cout << "Error opening the file." << endl;
        return 1;
    }

    string name;
    string firstStudent, lastStudent;

    if (inputFile >> name) {
        firstStudent = lastStudent = name;
    } else {
        cout << "No data found in the file." << endl;
        inputFile.close();
        return 1;
    }

    while (inputFile >> name) {
        if (name < firstStudent) {
            firstStudent = name;
        } else if (name > lastStudent) {
            lastStudent = name;
        }
    }

    cout << "First student in line: " << firstStudent << endl;
    cout << "Last student in line: " << lastStudent << endl;

    inputFile.close();

    return 0;
}
