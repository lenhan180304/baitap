#include <iostream>

class NumberArray {
private:
    double* numbers;
    int size;

public:
    // Constructor
    NumberArray(int);

    // Destructor
    ~NumberArray();

    // Member functions
    void storeNumber(int, double);
    double retrieveNumber(int) const;
    double getHighest() const;
    double getLowest() const;
    double getAverage() const;
};

// Constructor
NumberArray::NumberArray(int s) : size(s) {
    numbers = new double[size];
}

// Destructor
NumberArray::~NumberArray() {
    delete[] numbers;
}

// Store a number in any element of the array
void NumberArray::storeNumber(int index, double value) {
    if (index >= 0 && index < size) {
        numbers[index] = value;
    } else {
        std::cerr << "Error: Index out of bounds." << std::endl;
    }
}

// Retrieve a number from any element of the array
double NumberArray::retrieveNumber(int index) const {
    if (index >= 0 && index < size) {
        return numbers[index];
    } else {
        std::cerr << "Error: Index out of bounds." << std::endl;
        return 0.0; // Return a default value
    }
}

// Return the highest value stored in the array
double NumberArray::getHighest() const {
    double highest = numbers[0];
    for (int i = 1; i < size; ++i) {
        if (numbers[i] > highest) {
            highest = numbers[i];
        }
    }
    return highest;
}

// Return the lowest value stored in the array
double NumberArray::getLowest() const {
    double lowest = numbers[0];
    for (int i = 1; i < size; ++i) {
        if (numbers[i] < lowest) {
            lowest = numbers[i];
        }
    }
    return lowest;
}

// Return the average of all the numbers stored in the array
double NumberArray::getAverage() const {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += numbers[i];
    }
    return sum / size;
}

int main() {
    int arraySize;

    // Get the size of the array from the user
    std::cout << "Enter the size of the array: ";
    std::cin >> arraySize;

    // Create a NumberArray object
    NumberArray myArray(arraySize);

    // Store numbers in the array
    for (int i = 0; i < arraySize; ++i) {
        double value;
        std::cout << "Enter a number for element " << i << ": ";
        std::cin >> value;
        myArray.storeNumber(i, value);
    }

    // Display information about the array
    std::cout << "Highest value: " << myArray.getHighest() << std::endl;
    std::cout << "Lowest value: " << myArray.getLowest() << std::endl;
    std::cout << "Average: " << myArray.getAverage() << std::endl;

    return 0;
}
