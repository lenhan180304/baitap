#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Structure to hold monthly budget categories
struct MonthlyBudget {
    double housing;
    double utilities;
    double householdExpenses;
    double transportation;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double miscellaneous;
};

// Function prototypes
void enterExpenses(MonthlyBudget&);
void displayBudgetReport(const MonthlyBudget&);

int main() {
    MonthlyBudget monthlyBudget;

    // Get user input for expenses
    enterExpenses(monthlyBudget);

    // Display budget report
    displayBudgetReport(monthlyBudget);

    return 0;
}

// Function to enter expenses for each budget category
void enterExpenses(MonthlyBudget& budget) {
    cout << "Enter the amounts spent in each budget category for the month:\n";

    cout << "Housing: ";
    cin >> budget.housing;

    cout << "Utilities: ";
    cin >> budget.utilities;

    cout << "Household Expenses: ";
    cin >> budget.householdExpenses;

    cout << "Transportation: ";
    cin >> budget.transportation;

    cout << "Food: ";
    cin >> budget.food;

    cout << "Medical: ";
    cin >> budget.medical;

    cout << "Insurance: ";
    cin >> budget.insurance;

    cout << "Entertainment: ";
    cin >> budget.entertainment;

    cout << "Clothing: ";
    cin >> budget.clothing;

    cout << "Miscellaneous: ";
    cin >> budget.miscellaneous;
}

// Function to display budget report
void displayBudgetReport(const MonthlyBudget& budget) {
    cout << fixed << setprecision(2);

    cout << "\nBudget Report:\n";
    cout << "----------------------------------------------------\n";
    cout << "Category\tBudget\t\tActual\t\tDifference\n";
    cout << "----------------------------------------------------\n";

    // Display and calculate differences for each category
    cout << "Housing\t\t$500.00\t\t$" << budget.housing << "\t\t$" << budget.housing - 500.00 << endl;
    cout << "Utilities\t$150.00\t\t$" << budget.utilities << "\t\t$" << budget.utilities - 150.00 << endl;
    cout << "Household\t$65.00\t\t$" << budget.householdExpenses << "\t\t$" << budget.householdExpenses - 65.00 << endl;
    cout << "Transportation\t$50.00\t\t$" << budget.transportation << "\t\t$" << budget.transportation - 50.00 << endl;
    cout << "Food\t\t$250.00\t\t$" << budget.food << "\t\t$" << budget.food - 250.00 << endl;
    cout << "Medical\t\t$30.00\t\t$" << budget.medical << "\t\t$" << budget.medical - 30.00 << endl;
    cout << "Insurance\t$100.00\t\t$" << budget.insurance << "\t\t$" << budget.insurance - 100.00 << endl;
    cout << "Entertainment\t$150.00\t\t$" << budget.entertainment << "\t\t$" << budget.entertainment - 150.00 << endl;
    cout << "Clothing\t$75.00\t\t$" << budget.clothing << "\t\t$" << budget.clothing - 75.00 << endl;
    cout << "Miscellaneous\t$50.00\t\t$" << budget.miscellaneous << "\t\t$" << budget.miscellaneous - 50.00 << endl;

    // Calculate and display total difference
    double totalDifference =
        budget.housing - 500.00 + budget.utilities - 150.00 + budget.householdExpenses - 65.00 +
        budget.transportation - 50.00 + budget.food - 250.00 + budget.medical - 30.00 +
        budget.insurance - 100.00 + budget.entertainment - 150.00 + budget.clothing - 75.00 +
        budget.miscellaneous - 50.00;

    cout << "----------------------------------------------------\n";
    cout << "Total Difference\t\t\t\t\t$" << totalDifference << endl;
    cout << "----------------------------------------------------\n";
}
