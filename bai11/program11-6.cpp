#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure to store information about an inventory item
struct InventoryItem {
    int partNum;        // Part number
    string description; // Item description
    int onHand;         // Units on hand
    double price;       // Unit price
};

// Function prototypes
void getItem(InventoryItem&); // Argument passed by reference
void showItem(InventoryItem); // Argument passed by value

int main() {
    InventoryItem part;

    // Get information for an inventory item
    getItem(part);

    // Display the information for the inventory item
    showItem(part);

    return 0;
}

// Function to get information for an inventory item
void getItem(InventoryItem& p) {
    // Get the part number
    cout << "Enter the part number: ";
    cin >> p.partNum;

    // Get the part description
    cout << "Enter the part description: ";
    cin.ignore(); // Ignore the remaining newline character
    getline(cin, p.description);

    // Get the quantity on hand
    cout << "Enter the quantity on hand: ";
    cin >> p.onHand;

    // Get the unit price
    cout << "Enter the unit price: ";
    cin >> p.price;
}

// Function to display information for an inventory item
void showItem(InventoryItem p) {
    cout << fixed << showpoint << setprecision(2);
    cout << "Part Number: " << p.partNum << endl;
    cout << "Description: " << p.description << endl;
    cout << "Units On Hand: " << p.onHand << endl;
    cout << "Price: $" << p.price << endl;
}
