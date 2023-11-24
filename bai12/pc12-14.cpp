#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Structure to store inventory data
struct InventoryItem {
    string itemDescription;
    int quantityOnHand;
    double wholesaleCost;
    double retailCost;
    string dateAdded;
};

// Function prototypes
void calculateInventorySummary(const string& fileName);

int main() {
    const string fileName = "inventory.dat";

    calculateInventorySummary(fileName);

    return 0;
}

void calculateInventorySummary(const string& fileName) {
    ifstream inFile(fileName, ios::binary);

    if (!inFile.is_open()) {
        cerr << "Error: Unable to open the file for reading.\n";
        exit(1);
    }

    InventoryItem item;
    double totalWholesaleValue = 0.0;
    double totalRetailValue = 0.0;
    int totalQuantity = 0;

    inFile.read(reinterpret_cast<char*>(&item), sizeof(item));

    while (!inFile.eof()) {
        totalWholesaleValue += item.wholesaleCost * item.quantityOnHand;
        totalRetailValue += item.retailCost * item.quantityOnHand;
        totalQuantity += item.quantityOnHand;

        inFile.read(reinterpret_cast<char*>(&item), sizeof(item));
    }

    cout << fixed << setprecision(2);
    cout << "\nInventory Summary:\n";
    cout << "Total Wholesale Value: $" << totalWholesaleValue << endl;
    cout << "Total Retail Value: $" << totalRetailValue << endl;
    cout << "Total Quantity: " << totalQuantity << endl;

    inFile.close();
}
