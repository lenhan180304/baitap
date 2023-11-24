#include <iostream>
#include <iomanip>

using namespace std;

// Structure to represent a bin
struct Bin {
    string description; // Description of the part in the bin
    int numParts;       // Number of parts in the bin
};

const int NUM_BINS = 10;

// Function prototypes
void displayBins(const Bin bins[], int size);
void addParts(Bin& bin, int numToAdd);
void removeParts(Bin& bin, int numToRemove);

int main() {
    // Initialize bins with data
    Bin bins[NUM_BINS] = {
        {"Valve", 10},
        {"Bearing", 5},
        {"Bushing", 15},
        {"Coupling", 21},
        {"Flange", 7},
        {"Gear", 5},
        {"Gear Housing", 5},
        {"Vacuum Gripper", 25},
        {"Cable", 18},
        {"Rod", 12}
    };

    int choice;
    int selectedBin;

    do {
        // Display current bin data
        displayBins(bins, NUM_BINS);

        // Ask the user to select a bin or quit
        cout << "Enter the bin number to select (1-" << NUM_BINS << "), or enter 0 to quit: ";
        cin >> choice;

        if (choice >= 1 && choice <= NUM_BINS) {
            selectedBin = choice - 1; // Adjust for zero-based indexing

            // Display options for the selected bin
            cout << "Selected bin: " << bins[selectedBin].description << ", Parts: " << bins[selectedBin].numParts << endl;
            cout << "1. Add parts\n2. Remove parts\n3. Cancel\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    // Add parts to the selected bin
                    int numToAdd;
                    cout << "Enter the number of parts to add: ";
                    cin >> numToAdd;
                    addParts(bins[selectedBin], numToAdd);
                    break;

                case 2:
                    // Remove parts from the selected bin
                    int numToRemove;
                    cout << "Enter the number of parts to remove: ";
                    cin >> numToRemove;
                    removeParts(bins[selectedBin], numToRemove);
                    break;

                case 3:
                    // Cancel, do nothing
                    break;

                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
            }
        } else if (choice != 0) {
            cout << "Invalid bin number. Please enter a valid bin number or 0 to quit.\n";
        }

    } while (choice != 0);

    cout << "Program terminated.\n";

    return 0;
}

// Function to display the current state of bins
void displayBins(const Bin bins[], int size) {
    cout << "Inventory Bins:\n";
    cout << setw(15) << left << "Description" << setw(10) << "Parts" << endl;
    for (int i = 0; i < size; ++i) {
        cout << setw(15) << left << bins[i].description << setw(10) << bins[i].numParts << endl;
    }
    cout << endl;
}

// Function to add parts to a bin
void addParts(Bin& bin, int numToAdd) {
    if (numToAdd > 0) {
        // Input validation: No bin can hold more than 30 parts
        if (bin.numParts + numToAdd <= 30) {
            bin.numParts += numToAdd;
            cout << numToAdd << " parts added to the bin.\n";
        } else {
            cout << "Error: The bin can't hold more than 30 parts. No parts added.\n";
        }
    } else {
        cout << "Error: Number of parts to add must be greater than 0.\n";
    }
}

// Function to remove parts from a bin
void removeParts(Bin& bin, int numToRemove) {
    if (numToRemove > 0) {
        // Input validation: Don't accept negative values for the number of parts
        if (bin.numParts - numToRemove >= 0) {
            bin.numParts -= numToRemove;
            cout << numToRemove << " parts removed from the bin.\n";
        } else {
            cout << "Error: Not enough parts in the bin. No parts removed.\n";
        }
    } else {
        cout << "Error: Number of parts to remove must be greater than 0.\n";
    }
}
