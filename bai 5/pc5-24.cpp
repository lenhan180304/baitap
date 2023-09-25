#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("Random.txt");

    if (!inputFile) {
        cout << "Error opening the file." << endl;
        return 1;
    }

    int number;
    int count = 0;
    int sum = 0;
    double average = 0.0;

    while (inputFile >> number) {
        count++;
        sum += number;
    }

    if (count > 0) {
        average = static_cast<double>(sum) / count;
    }

    cout << "Number of numbers in the file: " << count << endl;
    cout << "Sum of all the numbers: " << sum << endl;
    cout << "Average of all the numbers: " << average << endl;

    inputFile.close();

    return 0;
}
