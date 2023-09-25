#include <iostream>
#include <iomanip>

int main() {
    int numYears;
    double totalRainfall = 0.0;
    const int numMonths = 12;

    std::cout << "Enter the number of years: ";
    std::cin >> numYears;

    if (numYears < 1) {
        std::cout << "Invalid input. Please enter a number of years greater than or equal to 1." << std::endl;
        return 1;
    }

    for (int year = 1; year <= numYears; ++year) {
        for (int month = 1; month <= numMonths; ++month) {
            double rainfall;
            std::cout << "Enter the inches of rainfall for Year " << year << ", Month " << month << ": ";
            std::cin >> rainfall;

            if (rainfall < 0.0) {
                std::cout << "Invalid input. Rainfall cannot be negative." << std::endl;
                return 1;
            }

            totalRainfall += rainfall;
        }
    }

    int totalMonths = numYears * numMonths;
    double averageRainfall = totalRainfall / totalMonths;

    std::cout << "Number of months: " << totalMonths << std::endl;
    std::cout << "Total inches of rainfall: " << totalRainfall << " inches" << std::endl;
    std::cout << "Average monthly rainfall: " << std::fixed << std::setprecision(2) << averageRainfall << " inches" << std::endl;

    return 0;
}
