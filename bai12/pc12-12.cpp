#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// Structure to store sales data for a division
struct DivisionData {
    string divisionName;
    int quarter;
    double quarterlySales;
};

// Function to read sales data from a file
void readSalesDataFromFile(const string& fileName, DivisionData salesData[][4]) {
    ifstream inFile(fileName);

    if (!inFile.is_open()) {
        cerr << "Error: Unable to open the file for reading.\n";
        exit(1);
    }

    while (inFile >> salesData[0][0].divisionName >> salesData[0][0].quarter >> salesData[0][0].quarterlySales) {
        for (int i = 1; i < 4; ++i) {
            inFile >> salesData[i][0].divisionName >> salesData[i][0].quarter >> salesData[i][0].quarterlySales;
        }
    }

    inFile.close();
}

int main() {
    const int NUM_DIVISIONS = 4;
    const int NUM_QUARTERS = 4;

    DivisionData salesData[NUM_DIVISIONS][NUM_QUARTERS];

    readSalesDataFromFile("sales_data.txt", salesData);

    // Calculate and display figures
    cout << "Total Corporate Sales for Each Quarter:\n";
    double totalQuarterlySales[NUM_QUARTERS] = {0};

    for (int j = 0; j < NUM_QUARTERS; ++j) {
        for (int i = 0; i < NUM_DIVISIONS; ++i) {
            totalQuarterlySales[j] += salesData[i][j].quarterlySales;
        }
        cout << "Quarter " << j + 1 << ": $" << totalQuarterlySales[j] << endl;
    }

    cout << "\nTotal Yearly Sales for Each Division:\n";
    double totalYearlySales[NUM_DIVISIONS] = {0};

    for (int i = 0; i < NUM_DIVISIONS; ++i) {
        for (int j = 0; j < NUM_QUARTERS; ++j) {
            totalYearlySales[i] += salesData[i][j].quarterlySales;
        }
        cout << salesData[i][0].divisionName << ": $" << totalYearlySales[i] << endl;
    }

    cout << "\nTotal Yearly Corporate Sales:\n";
    double totalYearlyCorporateSales = 0;

    for (int j = 0; j < NUM_QUARTERS; ++j) {
        for (int i = 0; i < NUM_DIVISIONS; ++i) {
            totalYearlyCorporateSales += salesData[i][j].quarterlySales;
        }
    }

    cout << "Total Corporate Sales: $" << totalYearlyCorporateSales << endl;

    cout << "\nAverage Quarterly Sales for the Divisions:\n";
    double averageQuarterlySales[NUM_DIVISIONS] = {0};

    for (int i = 0; i < NUM_DIVISIONS; ++i) {
        for (int j = 0; j < NUM_QUARTERS; ++j) {
            averageQuarterlySales[i] += salesData[i][j].quarterlySales;
        }
        averageQuarterlySales[i] /= NUM_QUARTERS;
        cout << salesData[i][0].divisionName << ": $" << averageQuarterlySales[i] << endl;
    }

    cout << "\nHighest and Lowest Quarters for the Corporation:\n";
    double highestQuarterSales = numeric_limits<double>::min();
    double lowestQuarterSales = numeric_limits<double>::max();
    int highestQuarter = 0;
    int lowestQuarter = 0;

    for (int j = 0; j < NUM_QUARTERS; ++j) {
        double totalQuarterSales = 0;
        for (int i = 0; i < NUM_DIVISIONS; ++i) {
            totalQuarterSales += salesData[i][j].quarterlySales;
        }
        if (totalQuarterSales > highestQuarterSales) {
            highestQuarterSales = totalQuarterSales;
            highestQuarter = j + 1;
        }
        if (totalQuarterSales < lowestQuarterSales) {
            lowestQuarterSales = totalQuarterSales;
            lowestQuarter = j + 1;
        }
    }

    cout << "Highest Quarter: " << highestQuarter << " with total sales: $" << highestQuarterSales << endl;
    cout << "Lowest Quarter: " << lowestQuarter << " with total sales: $" << lowestQuarterSales << endl;

    return 0;
}
