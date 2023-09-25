#include <iostream>

int main() {
    int startingPopulation, days;
    double dailyIncrease;

    // Input data from the user
    std::cout << "Enter the initial population (must be >= 2): ";
    std::cin >> startingPopulation;

    // Check the input data
    if (startingPopulation < 2) {
        std::cout << "Initial population must be at least 2. Exiting the program." << std::endl;
        return 1;
    }

    std::cout << "Enter the daily population increase (as a percentage): ";
    std::cin >> dailyIncrease;

    // Check the input data
    if (dailyIncrease < 0) {
        std::cout << "Daily population increase cannot be negative. Exiting the program." << std::endl;
        return 1;
    }

    std::cout << "Enter the number of days (must be >= 1): ";
    std::cin >> days;

    // Check the input data
    if (days < 1) {
        std::cout << "Number of days must be at least 1. Exiting the program." << std::endl;
        return 1;
    }

    // Calculate and display the population size for each day
    for (int day = 1; day <= days; ++day) {
        std::cout << "Day " << day << ": " << startingPopulation << " organisms" << std::endl;
        startingPopulation += startingPopulation * (dailyIncrease / 100.0);
    }

    return 0;
}
