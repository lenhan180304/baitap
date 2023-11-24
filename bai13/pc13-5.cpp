#include <iostream>
#include <string>

class RetailItem {
private:
    std::string description;
    int unitsOnHand;
    double price;

public:
    // Constructor
    RetailItem(const std::string& desc, int units, double itemPrice);

    // Accessor functions
    std::string getDescription() const;
    int getUnitsOnHand() const;
    double getPrice() const;

    // Mutator functions
    void setDescription(const std::string& desc);
    void setUnitsOnHand(int units);
    void setPrice(double itemPrice);
};

// Constructor
RetailItem::RetailItem(const std::string& desc, int units, double itemPrice)
    : description(desc), unitsOnHand(units), price(itemPrice) {}

// Accessor functions
std::string RetailItem::getDescription() const {
    return description;
}

int RetailItem::getUnitsOnHand() const {
    return unitsOnHand;
}

double RetailItem::getPrice() const {
    return price;
}

// Mutator functions
void RetailItem::setDescription(const std::string& desc) {
    description = desc;
}

void RetailItem::setUnitsOnHand(int units) {
    unitsOnHand = units;
}

void RetailItem::setPrice(double itemPrice) {
    price = itemPrice;
}

int main() {
    // Create instances of RetailItem
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);

    // Display information
    std::cout << "Item #1:\n";
    std::cout << "Description: " << item1.getDescription() << "\nUnits on Hand: " << item1.getUnitsOnHand()
              << "\nPrice: $" << item1.getPrice() << "\n\n";

    std::cout << "Item #2:\n";
    std::cout << "Description: " << item2.getDescription() << "\nUnits on Hand: " << item2.getUnitsOnHand()
              << "\nPrice: $" << item2.getPrice() << "\n\n";

    std::cout << "Item #3:\n";
    std::cout << "Description: " << item3.getDescription() << "\nUnits on Hand: " << item3.getUnitsOnHand()
              << "\nPrice: $" << item3.getPrice() << "\n";

    return 0;
}
