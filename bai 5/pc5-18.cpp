#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("People.txt");
    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    cout << "PRAIRIEVILLE POPULATION GROWTH" << endl;
    cout << "(each * represents 1,000 people)" << endl;

    int year = 1900;
    int population;

    while (inputFile >> population) {
        cout << year << " ";
        for (int i = 0; i < population / 1000; i++) {
            cout << "*";
        }
        cout << endl;
        year += 20;
    }

    inputFile.close();
    return 0;
}
