#include <iostream>
#include <iomanip>

class Population {
private:
    int population;
    int numBirths;
    int numDeaths;

public:
    // Constructors
    Population();
    Population(int pop, int births, int deaths);

    // Mutator functions
    void setPopulation(int pop);
    void setBirths(int births);
    void setDeaths(int deaths);

    // Accessor functions
    int getPopulation() const;
    int getBirths() const;
    int getDeaths() const;

    // Calculate birth rate and death rate
    double calculateBirthRate() const;
    double calculateDeathRate() const;
};

// Default constructor
Population::Population() : population(0), numBirths(0), numDeaths(0) {}

// Constructor with parameters
Population::Population(int pop, int births, int deaths)
    : population(pop), numBirths(births), numDeaths(deaths) {}

// Mutator function for population
void Population::setPopulation(int pop) {
    if (pop >= 1) {
        population = pop;
    } else {
        std::cerr << "Error: Population must be greater than or equal to 1." << std::endl;
    }
}

// Mutator function for births
void Population::setBirths(int births) {
    if (births >= 0) {
        numBirths = births;
    } else {
        std::cerr << "Error: Number of births cannot be negative." << std::endl;
    }
}

// Mutator function for deaths
void Population::setDeaths(int deaths) {
    if (deaths >= 0) {
        numDeaths = deaths;
    } else {
        std::cerr << "Error: Number of deaths cannot be negative." << std::endl;
    }
}

// Accessor function for population
int Population::getPopulation() const {
    return population;
}

// Accessor function for births
int Population::getBirths() const {
    return numBirths;
}

// Accessor function for deaths
int Population::getDeaths() const {
    return numDeaths;
}

// Calculate birth rate
double Population::calculateBirthRate() const {
    return static_cast<double>(numBirths) / population;
}

// Calculate death rate
double Population::calculateDeathRate() const {
    return static_cast<double>(numDeaths) / population;
}

int main() {
    // Demonstrate the Population class
    int userPopulation, userBirths, userDeaths;

    // Get population, number of births, and number of deaths from the user
    std::cout << "Enter the population: ";
    std::cin >> userPopulation;

    std::cout << "Enter the number of births: ";
    std::cin >> userBirths;

    std::cout << "Enter the number of deaths: ";
    std::cin >> userDeaths;

    // Create a Population object
    Population myPopulation(userPopulation, userBirths, userDeaths);

    // Display birth rate and death rate
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Birth Rate: " << myPopulation.calculateBirthRate() << std::endl;
    std::cout << "Death Rate: " << myPopulation.calculateDeathRate() << std::endl;

    return 0;
}
