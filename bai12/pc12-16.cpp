#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Customer {
    string name;
    string address;
    string cityStateZip;
    string phoneNumber;
    double accountBalance;
    string lastPaymentDate;
};

const string fileName = "customer_records.txt";

void displayMenu();
void enterNewRecord();
void searchAndDisplayRecord();
void searchAndDeleteRecord();
void searchAndChangeRecord();
void displayAllRecords();

int main() {
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                enterNewRecord();
                break;
            case 2:
                searchAndDisplayRecord();
                break;
            case 3:
                searchAndDeleteRecord();
                break;
            case 4:
                searchAndChangeRecord();
                break;
            case 5:
                displayAllRecords();
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}

void displayMenu() {
    cout << "\n1. Enter new record\n"
         << "2. Search and display record\n"
         << "3. Search and delete record\n"
         << "4. Search and change record\n"
         << "5. Display all records\n"
         << "6. Exit\n";
}

void enterNewRecord() {
    ofstream outFile(fileName, ios::app);

    if (!outFile.is_open()) {
        cerr << "Error: Unable to open the file for writing.\n";
        return;
    }

    Customer newCustomer;

    cout << "Enter customer details:\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, newCustomer.name);

    // Similar input for other fields...

    cout << "Account Balance: ";
    cin >> newCustomer.accountBalance;

    cout << "Last Payment Date: ";
    cin >> newCustomer.lastPaymentDate;

    outFile << newCustomer.name << ',' << newCustomer.address << ',' << newCustomer.cityStateZip << ','
            << newCustomer.phoneNumber << ',' << newCustomer.accountBalance << ',' << newCustomer.lastPaymentDate << '\n';

    outFile.close();
}

// Similar functions for search, delete, change, and display all records...

