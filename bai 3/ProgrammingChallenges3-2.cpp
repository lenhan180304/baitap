#include <iostream>
#include <iomanip>
using namespace std;

int main()

{
    int classA_tickets, classB_tickets, classC_tickets;
    double classA_price, classB_price, classC_price;
    double total_income;

    // Define the prices for each seating class
    classA_price = 15.0;
    classB_price = 12.0;
    classC_price = 9.0;

    // Ask the user to enter the number of tickets sold for each seating class
    cout << "Enter the number of tickets sold for Class A seats: ";
    cin >> classA_tickets;
    cout << "Enter the number of tickets sold for Class B seats: ";
    cin >> classB_tickets;
    cout << "Enter the number of tickets sold for Class C seats: ";
    cin >> classC_tickets;

    // Calculate the total income generated from ticket sales
    total_income = classA_tickets * classA_price + classB_tickets * classB_price + classC_tickets * classC_price;

    // Display the amount of income generated from ticket sales
    cout << fixed << setprecision(2);
    cout << "The income generated from ticket sales is: $" << total_income << endl;

    return 0;
}
