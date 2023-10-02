#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    string filename;
    
    // Get the filename from the user
    cout << "Enter the name of the file: ";
    cin >> filename;
    
    // Open the file
    ifstream inputFile(filename);
    
    // Check if the file is successfully opened
    if (!inputFile) {
        cerr << "Error opening file. Make sure the file exists and the name is correct." << endl;
        return 1;
    }
    
    vector<double> numbers;
    double number;
    
    // Read numbers from the file and store them in a vector
    while (inputFile >> number) {
        numbers.push_back(number);
    }
    
    // Close the file
    inputFile.close();
    
    if (numbers.empty()) {
        cerr << "No numbers found in the file." << endl;
        return 1;
    }
    
    // Calculate statistics
    double lowest = *min_element(numbers.begin(), numbers.end());
    double highest = *max_element(numbers.begin(), numbers.end());
    double total = accumulate(numbers.begin(), numbers.end(), 0.0);
    double average = total / numbers.size();
    
    // Display the statistics
    cout << fixed << setprecision(2);
    cout << "Lowest number: " << lowest << endl;
    cout << "Highest number: " << highest << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << average << endl;
    
    return 0;
}
