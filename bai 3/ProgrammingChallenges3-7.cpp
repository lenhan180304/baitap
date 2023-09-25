#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string movieName;
    int adultTicketsSold, childTicketsSold;
    double adultTicketPrice = 10.0, childTicketPrice = 6.0;
    double grossBoxOfficeProfit, netBoxOfficeProfit, amountPaidToDistributor;

    // Ask the user for the movie name and ticket sales
    cout << "Movie Name: ";
    getline(cin, movieName);
    cout << "Adult Tickets Sold: ";
    cin >> adultTicketsSold;
    cout << "Child Tickets Sold: ";
    cin >> childTicketsSold;

    // Calculate the gross box office profit
    grossBoxOfficeProfit = (adultTicketsSold * adultTicketPrice) + (childTicketsSold * childTicketPrice);

    // Calculate the net box office profit and amount paid to distributor
    netBoxOfficeProfit = grossBoxOfficeProfit * 0.2; // Assuming the theater keeps 20% of the revenue
    amountPaidToDistributor = grossBoxOfficeProfit - netBoxOfficeProfit;

    // Display the results
    cout << "Gross Box Office Profit: $" << fixed << setprecision(2) << grossBoxOfficeProfit << endl;
    cout << "Net Box Office Profit: $" << fixed << setprecision(2) << netBoxOfficeProfit << endl;
    cout << "Amount Paid to Distributor: $" << fixed << setprecision(2) << amountPaidToDistributor << endl;

    return 0;
}
