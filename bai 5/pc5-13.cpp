#include <iostream>
#include <climits> // For INT_MIN and INT_MAX constants

int main() {
    int number;
    int smallest = INT_MAX; // Initialize smallest to the largest possible integer
    int largest = INT_MIN; // Initialize largest to the smallest possible integer

    std::cout << "Enter a series of integers (-99 to end):" << std::endl;

    while (true) {
        std::cin >> number;

        if (number == -99) {
            break; // Exit the loop when -99 is entered
        }

        if (number < smallest) {
            smallest = number; // Update smallest if a smaller number is entered
        }

        if (number > largest) {
            largest = number; // Update largest if a larger number is entered
        }
    }

    if (largest == INT_MIN) {
        std::cout << "No numbers were entered." << std::endl;
    } else {
        std::cout << "Smallest number entered: " << smallest << std::endl;
        std::cout << "Largest number entered: " << largest << std::endl;
    }

    return 0;
}
