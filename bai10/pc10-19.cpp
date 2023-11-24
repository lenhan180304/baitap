#include <iostream>
#include <iomanip>
#include <string>

std::string convertToWords(int number);

int main() {
    // Get user input
    std::string date, payeeName;
    double amount;

    std::cout << "Enter the date (mm/dd/yyyy): ";
    std::getline(std::cin, date);

    std::cout << "Enter the payee's name: ";
    std::getline(std::cin, payeeName);

    do {
        std::cout << "Enter the amount of the check (up to $10,000): $";
        std::cin >> amount;

        if (amount < 0 || amount > 10000) {
            std::cout << "Invalid amount. Please enter a non-negative amount up to $10,000." << std::endl;
        }

    } while (amount < 0 || amount > 10000);

    // Display simulated check
    std::cout << "\nDate: " << date << std::endl;
    std::cout << "Pay to the Order of: " << payeeName << " $" << std::fixed << std::setprecision(2) << amount << std::endl;

    // Convert the amount to words
    std::string amountInWords = convertToWords(static_cast<int>(amount));

    std::cout << amountInWords << std::endl;

    return 0;
}

std::string convertToWords(int number) {
    // Function to convert the numeric value to words
    // (You may need to extend this function for higher amounts)

    const std::string units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const std::string teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const std::string tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    std::string result;

    // Extract digits
    int thousand = number / 1000;
    int hundred = (number % 1000) / 100;
    int ten = (number % 100) / 10;
    int unit = number % 10;

    if (thousand > 0) {
        result += units[thousand] + " thousand ";
    }

    if (hundred > 0) {
        result += units[hundred] + " hundred ";
    }

    if (ten == 1 && unit > 0) {
        result += teens[unit] + " ";
    } else {
        if (ten > 0) {
            result += tens[ten] + " ";
        }

        if (unit > 0) {
            result += units[unit] + " ";
        }
    }

    return result;
}
