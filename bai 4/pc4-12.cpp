#include <iostream>

double calculate_total_cost(int units_sold) {
    const double package_price = 99.0;
    double total_cost = 0.0;

    if (units_sold >= 10 && units_sold <= 19) {
        total_cost = units_sold * package_price * 0.8;
    } else if (units_sold >= 20 && units_sold <= 49) {
        total_cost = units_sold * package_price * 0.7;
    } else if (units_sold >= 50 && units_sold <= 99) {
        total_cost = units_sold * package_price * 0.6;
    } else if (units_sold >= 100) {
        total_cost = units_sold * package_price * 0.5;
    } else {
        std::cout << "Invalid quantity. Quantity must be greater than 0." << std::endl;
    }

    return total_cost;
}

int main() {
    int units_sold;

    std::cout << "Enter the number of units sold: ";
    std::cin >> units_sold;

    double total_cost = calculate_total_cost(units_sold);

    if (total_cost > 0) {
        std::cout << "The total cost of the purchase is $" << total_cost << std::endl;
    }

    return 0;
}
