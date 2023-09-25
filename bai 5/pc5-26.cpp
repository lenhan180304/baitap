#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ofstream outputFile("SavingsAccountReport.txt");
    
    if (!outputFile) {
        cout << "Error opening the file." << endl;
        return 1;
    }
    
    double annualInterestRate, startingBalance, monthlyDeposit;
    int numMonths;
    
    cout << "Enter the annual interest rate (as a decimal): ";
    cin >> annualInterestRate;
    
    cout << "Enter the starting balance: ";
    cin >> startingBalance;
    
    cout << "Enter the monthly deposit: ";
    cin >> monthlyDeposit;
    
    cout << "Enter the number of months: ";
    cin >> numMonths;
    
    outputFile << "Month\tStarting Balance\tMonthly Deposit\tInterest Earned\tEnding Balance\n";
    
    for (int month = 1; month <= numMonths; ++month) {
        double interestEarned = (startingBalance + monthlyDeposit) * (annualInterestRate / 12.0);
        double endingBalance = startingBalance + monthlyDeposit + interestEarned;
        
        outputFile << month << "\t$" << fixed << setprecision(2) << startingBalance << "\t\t$" << monthlyDeposit << "\t\t$" << interestEarned << "\t\t$" << endingBalance << endl;
        
        startingBalance = endingBalance;
    }
    
    outputFile.close();
    
    cout << "Report saved to SavingsAccountReport.txt" << endl;
    
    return 0;
}
