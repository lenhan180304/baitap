#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>

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
void displayMenu();
void addRecordToFile(const string& fileName);
void displayRecord(const string& fileName);
bool changeRecord(const string& fileName);

int main() {
    const string fileName = "inventory.dat";
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecordToFile(fileName);
                break;
            case 2:
                displayRecord(fileName);
                break;
            case 3:
                if (changeRecord(fileName)) {
                    cout << "Record updated successfully.\n";
                } else {
                    cout << "Failed to update record.\n";
                }
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    cout << "\nInventory Program Menu:\n";
    cout << "1. Add new record\n";
    cout << "2. Display a record\n";
    cout << "3. Change a record\n";
    cout << "4. Exit\n";
}

void addRecordToFile(const string& fileName) {
    ofstream outFile(fileName, ios::app | ios::binary);

    if (!outFile.is_open()) {
        cerr << "Error: Unable to open the file for writing.\n";
        exit(1);
    }

    InventoryItem newItem;

    cout << "Enter Item Description: ";
    cin.ignore();
    getline(cin, newItem.itemDescription);

    cout << "Enter Quantity on Hand: ";
    cin >> newItem.quantityOnHand;

    while (newItem.quantityOnHand < 0) {
        cout << "Quantity on Hand cannot be less than 0. Enter a valid quantity: ";
        cin >> newItem.quantityOnHand;
    }

    cout << "Enter Wholesale Cost: ";
    cin >> newItem.wholesaleCost;

    while (newItem.wholesaleCost < 0) {
        cout << "Wholesale Cost cannot be less than 0. Enter a valid cost: ";
        cin >> newItem.wholesaleCost;
    }

    cout << "Enter Retail Cost: ";
    cin >> newItem.retailCost;

    while (newItem.retailCost < 0) {
        cout << "Retail Cost cannot be less than 0. Enter a valid cost: ";
        cin >> newItem.retailCost;
    }

    time_t now = time(0);
    newItem.dateAdded = ctime(&now);

    outFile.write(reinterpret_cast<char*>(&newItem), sizeof(newItem));

    outFile.close();

    cout << "Record added successfully.\n";
}

void displayRecord(const string& fileName) {
    ifstream inFile(fileName, ios::binary);

    if (!inFile.is_open()) {
        cerr << "Error: Unable to open the file for reading.\n";
        exit(1);
    }

    InventoryItem item;

    cout << "\nEnter the record number to display: ";
    int recordNumber;
    cin >> recordNumber;

    inFile.seekg((recordNumber - 1) * sizeof(InventoryItem), ios::beg);
    inFile.read(reinterpret_cast<char*>(&item), sizeof(item));

    if (inFile.eof()) {
        cout << "Record not found.\n";
    } else {
        cout << "\nRecord Number: " << recordNumber << endl;
        cout << "Item Description: " << item.itemDescription << endl;
        cout << "Quantity on Hand: " << item.quantityOnHand << endl;
        cout << fixed << setprecision(2);
        cout << "Wholesale Cost: $" << item.wholesaleCost << endl;
        cout << "Retail Cost: $" << item.retailCost << endl;
        cout << "Date Added to Inventory: " << item.dateAdded << endl;
    }

    inFile.close();
}

bool changeRecord(const string& fileName) {
    fstream file(fileName, ios::in | ios::out | ios::binary);

    if (!file.is_open()) {
        cerr << "Error: Unable to open the file for reading and writing.\n";
        exit(1);
    }

    InventoryItem item;

    cout << "\nEnter the record number to change: ";
    int recordNumber;
    cin >> recordNumber;

    file.seekg((recordNumber - 1) * sizeof(InventoryItem), ios::beg);
    file.read(reinterpret_cast<char*>(&item), sizeof(item));

    if (file.eof()) {
        cout << "Record not found.\n";
        file.close();
        return false;
    }

    // Display the existing record
    cout << "\nExisting Record:\n";
    cout << "Item Description: " << item.itemDescription << endl;
    cout << "Quantity on Hand: " << item.quantityOnHand << endl;
    cout << fixed << setprecision(2);
    cout << "Wholesale Cost: $" << item.wholesaleCost << endl;
    cout << "Retail Cost: $" << item.retailCost << endl;

    // Get the new data
    cout << "\nEnter the new data:\n";
    cout << "Item Description: ";
    cin.ignore();
    getline(cin, item.itemDescription);

    cout << "Quantity on Hand: ";
    cin >> item.quantityOnHand;

    while (item.quantityOnHand < 0) {
        cout << "Quantity on Hand cannot be less than 0. Enter a valid quantity: ";
        cin >> item.quantityOnHand;
    }

    cout << "Wholesale Cost: ";
    cin >> item.wholesaleCost;

    while (item.wholesaleCost < 0) {
        cout << "Wholesale Cost cannot be less than 0. Enter a valid cost: ";
        cin >> item.wholesaleCost;
    }

    cout << "Retail Cost: ";
    cin >> item.retailCost;

    while (item.retailCost < 0) {
        cout << "Retail Cost cannot be less than 0. Enter a valid cost: ";
        cin >> item.retailCost;
    }

    // Write the updated record
    file.seekp((recordNumber - 1) * sizeof(InventoryItem), ios::beg);
    file.write(reinterpret_cast<char*>(&item), sizeof(item));

    file.close();

    return true;
}
