#include <iostream>
using namespace std;

int main() {
    double budget;
    double expense;
    double totalExpenses = 0.0;

    // Ask the user for the budget amount
    cout << "Enter your budget for the month: $";
    cin >> budget;

    // Input loop for expenses
    char continueInput = 'y';
    while (continueInput == 'y' || continueInput == 'Y') {
        cout << "Enter an expense: $";
        cin >> expense;
        totalExpenses += expense;

        cout << "Do you have another expense? (y/n): ";
        cin >> continueInput;
    }

    // Calculate the budget analysis
    double difference = budget - totalExpenses;

    // Display the result
    cout << "\nBudget Analysis\n";
    cout << "----------------\n";
    cout << "Budgeted amount: $" << budget << endl;
    cout << "Total expenses: $" << totalExpenses << endl;

    if (difference >= 0) {
        cout << "You are under budget by $" << difference << endl;
    } else {
        cout << "You are over budget by $" << -difference << endl;
    }

    return 0;
}
