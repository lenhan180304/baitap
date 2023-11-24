#include <iostream>

class PayRoll {
private:
    double hourlyPayRate;
    double hoursWorked;
    double totalPay;

public:
    // Constructors
    PayRoll();
    PayRoll(double rate, double hours);

    // Member functions
    void setHourlyPayRate(double rate);
    void setHoursWorked(double hours);
    void calculateTotalPay();
    double getTotalPay() const;
};

// Default constructor
PayRoll::PayRoll() : hourlyPayRate(0.0), hoursWorked(0.0), totalPay(0.0) {}

// Parameterized constructor
PayRoll::PayRoll(double rate, double hours) : hourlyPayRate(rate), hoursWorked(hours), totalPay(0.0) {}

// Set hourly pay rate
void PayRoll::setHourlyPayRate(double rate) {
    hourlyPayRate = rate;
}

// Set hours worked
void PayRoll::setHoursWorked(double hours) {
    // Validate hours worked
    if (hours >= 0.0 && hours <= 60.0) {
        hoursWorked = hours;
    } else {
        std::cerr << "Error: Invalid hours worked. Must be between 0 and 60." << std::endl;
    }
}

// Calculate total pay
void PayRoll::calculateTotalPay() {
    totalPay = hourlyPayRate * hoursWorked;
}

// Get total pay
double PayRoll::getTotalPay() const {
    return totalPay;
}

int main() {
    const int NUM_EMPLOYEES = 7;
    PayRoll employees[NUM_EMPLOYEES];
    double hours;

    // Get hours worked for each employee
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        std::cout << "Enter the number of hours worked for employee " << i + 1 << ": ";
        std::cin >> hours;
        employees[i].setHoursWorked(hours);
    }

    // Set hourly pay rate (assumed to be the same for all employees)
    double hourlyRate;
    std::cout << "Enter the hourly pay rate for all employees: ";
    std::cin >> hourlyRate;

    // Set hourly pay rate for all employees
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        employees[i].setHourlyPayRate(hourlyRate);
    }

    // Calculate and display total pay for each employee
    std::cout << "\nTotal Pay for Each Employee:\n";
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        employees[i].calculateTotalPay();
        std::cout << "Employee " << i + 1 << ": $" << employees[i].getTotalPay() << std::endl;
    }

    return 0;
}
