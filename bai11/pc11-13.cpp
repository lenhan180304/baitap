#include <iostream>
#include <iomanip>

using namespace std;

// Structure to store drink information
struct Drink {
    string name;
    double cost;
    int quantity;
};

// Function prototypes
void displayMenu(const Drink[], int);
void purchaseDrink(Drink&);

int main() {
    const int NUM_DRINKS = 5;
    Drink drinks[NUM_DRINKS] = {
        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grape Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
    };

    double totalEarnings = 0.0;
    char choice;

    do {
        displayMenu(drinks, NUM_DRINKS);

        cout << "Enter your choice (Q to quit): ";
        cin >> choice;
        choice = toupper(choice);

        if (choice >= 'A' && choice <= 'E') {
            purchaseDrink(drinks[choice - 'A']);
            totalEarnings += drinks[choice - 'A'].cost;
        } else if (choice != 'Q') {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 'Q');

    cout << "Total earnings: $" << fixed << setprecision(2) << totalEarnings << endl;

    return 0;
}

// Function to display the drink menu
void displayMenu(const Drink drinks[], int numDrinks) {
    cout << "\nDrink Machine Menu:\n";
    cout << "---------------------\n";
    for (int i = 0; i < numDrinks; ++i) {
        cout << static_cast<char>('A' + i) << ". " << drinks[i].name << " - $" << fixed << setprecision(2) << drinks[i].cost;
        if (drinks[i].quantity == 0) {
            cout << " (Sold Out)";
        }
        cout << endl;
    }
}

// Function to handle the drink purchase
void purchaseDrink(Drink& d) {
    if (d.quantity > 0) {
        double amount;
        cout << "Enter the amount of money (up to $1.00): $";
        cin >> amount;

        if (amount < 0.0 || amount > 1.0) {
            cout << "Invalid amount. Please enter a value between $0.00 and $1.00.\n";
        } else if (amount < d.cost) {
            cout << "Insufficient funds. Please insert more money.\n";
        } else {
            double change = amount - d.cost;
            cout << "Dispensing " << d.name << ". Change: $" << fixed << setprecision(2) << change << endl;
            d.quantity--;
        }
    } else {
        cout << "Sorry, " << d.name << " is sold out.\n";
    }
}
