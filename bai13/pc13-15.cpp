#include <iostream>
#include <cmath>

class MortgagePayment {
private:
    double loanAmount;
    double annualInterestRate;
    int numberOfYears;

public:
    MortgagePayment();
    void setLoanAmount(double amount);
    void setAnnualInterestRate(double rate);
    void setNumberOfYears(int years);
    double calculateMonthlyPayment() const;
    double calculateTotalAmountPaid() const;
};

MortgagePayment::MortgagePayment() : loanAmount(0), annualInterestRate(0), numberOfYears(0) {}

void MortgagePayment::setLoanAmount(double amount) {
    if (amount >= 0) {
        loanAmount = amount;
    } else {
        std::cerr << "Error: Loan amount cannot be negative.\n";
    }
}

void MortgagePayment::setAnnualInterestRate(double rate) {
    if (rate >= 0) {
        annualInterestRate = rate;
    } else {
        std::cerr << "Error: Annual interest rate cannot be negative.\n";
    }
}

void MortgagePayment::setNumberOfYears(int years) {
    if (years >= 0) {
        numberOfYears = years;
    } else {
        std::cerr << "Error: Number of years cannot be negative.\n";
    }
}

double MortgagePayment::calculateMonthlyPayment() const {
    if (annualInterestRate == 0) {
        return loanAmount / (numberOfYears * 12);
    }

    double monthlyRate = annualInterestRate / 12 / 100;
    double numPayments = numberOfYears * 12;

    double monthlyPayment = (loanAmount * monthlyRate) /
                            (1 - std::pow(1 + monthlyRate, -numPayments));

    return monthlyPayment;
}

double MortgagePayment::calculateTotalAmountPaid() const {
    return calculateMonthlyPayment() * numberOfYears * 12;
}

int main() {
    MortgagePayment mortgage;

    // Set loan details
    mortgage.setLoanAmount(100000); // Replace with the desired loan amount
    mortgage.setAnnualInterestRate(5); // Replace with the desired annual interest rate
    mortgage.setNumberOfYears(30); // Replace with the desired number of years

    // Display results
    std::cout << "Monthly Payment: $" << mortgage.calculateMonthlyPayment() << std::endl;
    std::cout << "Total Amount Paid: $" << mortgage.calculateTotalAmountPaid() << std::endl;

    return 0;
}
