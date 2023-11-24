#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to store sales data for a division
struct DivisionData {
    string divisionName;
    int quarter;
    double quarterlySales;
};

// Function to get valid sales input (non-negative)
double getValidSalesInput() {
    double sales;
    do {
        cout << "Enter quarterly sales (non-negative): ";
        cin >> sales;
        if (sales < 0) {
            cout << "Invalid input. Please enter a non-negative number.\n";
        }
    } while (sales < 0);
    return sales;
}

// Function to get sales data for a division
DivisionData getDivisionData(const string& divisionName, int quarter) {
    DivisionData data;
    data.divisionName = divisionName;
    data.quarter = quarter;
    data.quarterlySales = getValidSalesInput();
    return data;
}

int main() {
    const int NUM_DIVISIONS = 4;
    const int NUM_QUARTERS = 4;

    DivisionData salesData[NUM_DIVISIONS][NUM_QUARTERS];

    ofstream outFile("sales_data.txt");

    if (!outFile.is_open()) {
        cerr << "Error: Unable to open the file for writing.\n";
        return 1;
    }

    // Get sales data for each division and quarter
    for (int i = 0; i < NUM_DIVISIONS; ++i) {
        string divisionName;
        switch (i) {
            case 0: divisionName = "East"; break;
            case 1: divisionName = "West"; break;
            case 2: divisionName = "North"; break;
            case 3: divisionName = "South"; break;
        }

        for (int j = 0; j < NUM_QUARTERS; ++j) {
            salesData[i][j] = getDivisionData(divisionName, j + 1);

            // Write the data to the file
            outFile << salesData[i][j].divisionName << " "
                    << salesData[i][j].quarter << " "
                    << salesData[i][j].quarterlySales << endl;
        }
    }

    outFile.close();

    cout << "Sales data has been written to sales_data.txt.\n";

    return 0;
}
