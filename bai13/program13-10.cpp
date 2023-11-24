#include <iostream>
#include <iomanip>

class Sale {
private:
    double cost;
    double taxRate;

public:
    // Constructor with a default argument for tax rate
    Sale(double itemCost, double tax = 0.05) : cost(itemCost), taxRate(tax) {}

    // Member functions to calculate tax and total
    double getTax() const {
        return cost * taxRate;
    }

    double getTotal() const {
        return cost + getTax();
    }
};

int main() {
    double cost; // To hold the item cost

    // Get the cost of the item.
    std::cout << "Enter the cost of the item: ";
    std::cin >> cost;

    // Create a Sale object for this transaction.
    // Specify the item cost, but use the default tax rate of 5 percent.
    Sale itemSale(cost);

    // Set numeric output formatting.
    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    // Display the sales tax and total.
    std::cout << "The amount of sales tax is $" << itemSale.getTax() << std::endl;
    std::cout << "The total of the sale is $" << itemSale.getTotal() << std::endl;

    return 0;
}
