#include <iostream>
#include <string>

using namespace std;

const int NUM_ACCOUNTS = 10;

// Structure to store customer account data
struct CustomerAccount {
    string name;
    string address;
    string cityStateZip;
    string telephoneNumber;
    double accountBalance;
    string dateLastPayment;
};

// Function prototypes
void displayMenu();
void inputAccountData(CustomerAccount&);
void displayAllData(const CustomerAccount[]);
void modifyAccountData(CustomerAccount[]);
void searchAccountByName(const CustomerAccount[]);

int main() {
    CustomerAccount accounts[NUM_ACCOUNTS];

    int choice;

    do {
        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputAccountData(accounts[NUM_ACCOUNTS]);
                break;
            case 2:
                modifyAccountData(accounts);
                break;
            case 3:
                displayAllData(accounts);
                break;
            case 4:
                searchAccountByName(accounts);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\nCustomer Accounts Menu:\n";
    cout << "1. Enter new account data\n";
    cout << "2. Modify account data\n";
    cout << "3. Display all account data\n";
    cout << "4. Search account by name\n";
    cout << "5. Exit\n";
}

void inputAccountData(CustomerAccount& account) {
    cout << "Enter customer name: ";
    cin.ignore();  // Ignore the newline character left in the buffer
    getline(cin, account.name);

    cout << "Enter customer address: ";
    getline(cin, account.address);

    cout << "Enter city, state, and ZIP: ";
    getline(cin, account.cityStateZip);

    cout << "Enter telephone number: ";
    getline(cin, account.telephoneNumber);

    // Input account balance, validating for negative values
    do {
        cout << "Enter account balance: $";
        cin >> account.accountBalance;
    } while (account.accountBalance < 0);

    cout << "Enter date of last payment: ";
    cin.ignore();  // Ignore the newline character left in the buffer
    getline(cin, account.dateLastPayment);

    cout << "Account data entered successfully!\n";
}

void displayAllData(const CustomerAccount accounts[]) {
    cout << "\nCustomer Account Data:\n";
    cout << "-----------------------------------------------------------------------\n";
    cout << "Name\t\tAddress\t\tCity, State, ZIP\t\tTelephone\tAccount Balance\tDate of Last Payment\n";
    cout << "-----------------------------------------------------------------------\n";

    for (int i = 0; i < NUM_ACCOUNTS; ++i) {
        cout << accounts[i].name << "\t\t" << accounts[i].address << "\t\t" << accounts[i].cityStateZip << "\t\t"
             << accounts[i].telephoneNumber << "\t" << accounts[i].accountBalance << "\t\t" << accounts[i].dateLastPayment << "\n";
    }

    cout << "-----------------------------------------------------------------------\n";
}

void modifyAccountData(CustomerAccount accounts[]) {
    int accountNumber;

    cout << "Enter the account number you want to modify (1-" << NUM_ACCOUNTS << "): ";
    cin >> accountNumber;

    if (accountNumber >= 1 && accountNumber <= NUM_ACCOUNTS) {
        cout << "Modifying account data for account number " << accountNumber << ":\n";
        inputAccountData(accounts[accountNumber - 1]);
    } else {
        cout << "Invalid account number. Please enter a valid account number.\n";
    }
}

void searchAccountByName(const CustomerAccount accounts[]) {
    string searchName;

    cout << "Enter part of the customer's name to search: ";
    cin.ignore();  // Ignore the newline character left in the buffer
    getline(cin, searchName);

    bool found = false;

    cout << "\nSearch Results:\n";
    cout << "-----------------------------------------------------------------------\n";
    cout << "Name\t\tAddress\t\tCity, State, ZIP\t\tTelephone\tAccount Balance\tDate of Last Payment\n";
    cout << "-----------------------------------------------------------------------\n";

    for (int i = 0; i < NUM_ACCOUNTS; ++i) {
        if (accounts[i].name.find(searchName) != string::npos) {
            cout << accounts[i].name << "\t\t" << accounts[i].address << "\t\t" << accounts[i].cityStateZip << "\t\t"
                 << accounts[i].telephoneNumber << "\t" << accounts[i].accountBalance << "\t\t" << accounts[i].dateLastPayment << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No matching accounts found.\n";
    }

    cout << "-----------------------------------------------------------------------\n";
}
