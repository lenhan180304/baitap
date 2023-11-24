#include <iostream>
#include <string>

using namespace std;

// Structure to store corporate division data
struct CorporateDivision {
    string divisionName;
    double firstQuarterSales;
    double secondQuarterSales;
    double thirdQuarterSales;
    double fourthQuarterSales;
    double totalAnnualSales;
    double averageQuarterlySales;
};

// Function to input sales data for a division and calculate total and average sales
void inputSalesData(CorporateDivision& division) {
    cout << "Enter sales data for " << division.divisionName << " division:\n";
    
    // Input sales for each quarter, validating for negative numbers
    do {
        cout << "First Quarter Sales: $";
        cin >> division.firstQuarterSales;
    } while (division.firstQuarterSales < 0);

    do {
        cout << "Second Quarter Sales: $";
        cin >> division.secondQuarterSales;
    } while (division.secondQuarterSales < 0);

    do {
        cout << "Third Quarter Sales: $";
        cin >> division.thirdQuarterSales;
    } while (division.thirdQuarterSales < 0);

    do {
        cout << "Fourth Quarter Sales: $";
        cin >> division.fourthQuarterSales;
    } while (division.fourthQuarterSales < 0);

    // Calculate total annual sales and average quarterly sales
    division.totalAnnualSales = division.firstQuarterSales +
                               division.secondQuarterSales +
                               division.thirdQuarterSales +
                               division.fourthQuarterSales;

    division.averageQuarterlySales = division.totalAnnualSales / 4.0;
}

// Function to display sales data for a division
void displaySalesData(const CorporateDivision& division) {
    cout << "\nSales data for " << division.divisionName << " division:\n";
    cout << "First Quarter Sales: $" << division.firstQuarterSales << endl;
    cout << "Second Quarter Sales: $" << division.secondQuarterSales << endl;
    cout << "Third Quarter Sales: $" << division.thirdQuarterSales << endl;
    cout << "Fourth Quarter Sales: $" << division.fourthQuarterSales << endl;
    cout << "Total Annual Sales: $" << division.totalAnnualSales << endl;
    cout << "Average Quarterly Sales: $" << division.averageQuarterlySales << endl;
}

int main() {
    // Create structure variables for each division
    CorporateDivision eastDivision = {"East"};
    CorporateDivision westDivision = {"West"};
    CorporateDivision northDivision = {"North"};
    CorporateDivision southDivision = {"South"};

    // Input and display sales data for each division
    inputSalesData(eastDivision);
    displaySalesData(eastDivision);

    inputSalesData(westDivision);
    displaySalesData(westDivision);

    inputSalesData(northDivision);
    displaySalesData(northDivision);

    inputSalesData(southDivision);
    displaySalesData(southDivision);

    return 0;
}
