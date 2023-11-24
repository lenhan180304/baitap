#include <iostream>

class Inventory {
private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;

public:
    // Constructors
    Inventory();
    Inventory(int number, double itemCost, int itemQuantity);

    // Setter functions
    void setItemNumber(int number);
    void setQuantity(int itemQuantity);
    void setCost(double itemCost);
    void setTotalCost();

    // Getter functions
    int getItemNumber() const;
    int getQuantity() const;
    double getCost() const;
    double getTotalCost() const;
};

// Default constructor
Inventory::Inventory() : itemNumber(0), quantity(0), cost(0.0), totalCost(0.0) {}

// Constructor #2
Inventory::Inventory(int number, double itemCost, int itemQuantity)
    : itemNumber(number), cost(itemCost), quantity(itemQuantity) {
    setTotalCost();
}

// Setter functions
void Inventory::setItemNumber(int number) {
    if (number >= 0) {
        itemNumber = number;
    } else {
        std::cerr << "Error: Item number cannot be negative.\n";
    }
}

void Inventory::setQuantity(int itemQuantity) {
    if (itemQuantity >= 0) {
        quantity = itemQuantity;
        setTotalCost();
    } else {
        std::cerr << "Error: Quantity cannot be negative.\n";
    }
}

void Inventory::setCost(double itemCost) {
    if (itemCost >= 0) {
        cost = itemCost;
        setTotalCost();
    } else {
        std::cerr << "Error: Cost cannot be negative.\n";
    }
}

void Inventory::setTotalCost() {
    totalCost = quantity * cost;
}

// Getter functions
int Inventory::getItemNumber() const {
    return itemNumber;
}

int Inventory::getQuantity() const {
    return quantity;
}

double Inventory::getCost() const {
    return cost;
}

double Inventory::getTotalCost() const {
    return totalCost;
}

int main() {
    // Demonstrate the Inventory class
    Inventory item1(101, 5.99, 25);
    Inventory item2;

    // Set values for item2 using setter functions
    item2.setItemNumber(102);
    item2.setQuantity(30);
    item2.setCost(9.99);

    // Display information for item1 and item2
    std::cout << "Item #1:\n";
    std::cout << "Item Number: " << item1.getItemNumber() << "\nQuantity: " << item1.getQuantity()
              << "\nCost: $" << item1.getCost() << "\nTotal Cost: $" << item1.getTotalCost() << "\n\n";

    std::cout << "Item #2:\n";
    std::cout << "Item Number: " << item2.getItemNumber() << "\nQuantity: " << item2.getQuantity()
              << "\nCost: $" << item2.getCost() << "\nTotal Cost: $" << item2.getTotalCost() << "\n";

    return 0;
}
