#include <iostream>
#include <iomanip>
#include <string>

class InventoryItem {
private:
    std::string description;
    double cost;
    int unitsOnHand;

public:
    InventoryItem();
    InventoryItem(std::string desc, double c, int units);
    void setDescription(std::string desc);
    void setCost(double c);
    void setUnitsOnHand(int units);
    std::string getDescription() const;
    double getCost() const;
    int getUnitsOnHand() const;
    void displayItem() const;
};

InventoryItem::InventoryItem() : description(""), cost(0.0), unitsOnHand(0) {}

InventoryItem::InventoryItem(std::string desc, double c, int units)
    : description(desc), cost(c), unitsOnHand(units) {}

void InventoryItem::setDescription(std::string desc) {
    description = desc;
}

void InventoryItem::setCost(double c) {
    cost = c;
}

void InventoryItem::setUnitsOnHand(int units) {
    unitsOnHand = units;
}

std::string InventoryItem::getDescription() const {
    return description;
}

double InventoryItem::getCost() const {
    return cost;
}

int InventoryItem::getUnitsOnHand() const {
    return unitsOnHand;
}

void InventoryItem::displayItem() const {
    std::cout << "Description: " << description << "\n";
    std::cout << "Cost: $" << cost << "\n";
    std::cout << "Units on Hand: " << unitsOnHand << "\n";
}

class CashRegister {
private:
    double salesTaxRate;

public:
    CashRegister();
    double calculateSubtotal(const InventoryItem &item, int quantity) const;
    double calculateTax(double subtotal) const;
    double calculateTotal(double subtotal, double tax) const;
    void processPurchase(const InventoryItem &item, int quantity) const;
};

CashRegister::CashRegister() : salesTaxRate(0.06) {}

double CashRegister::calculateSubtotal(const InventoryItem &item, int quantity) const {
    double unitPrice = item.getCost() * 1.3; // 30% profit
    return unitPrice * quantity;
}

double CashRegister::calculateTax(double subtotal) const {
    return subtotal * salesTaxRate;
}

double CashRegister::calculateTotal(double subtotal, double tax) const {
    return subtotal + tax;
}

void CashRegister::processPurchase(const InventoryItem &item, int quantity) const {
    double subtotal = calculateSubtotal(item, quantity);
    double tax = calculateTax(subtotal);
    double total = calculateTotal(subtotal, tax);

    std::cout << "Purchase Subtotal: $" << std::fixed << std::setprecision(2) << subtotal << "\n";
    std::cout << "Sales Tax: $" << tax << "\n";
    std::cout << "Purchase Total: $" << total << "\n";

    // Adjust the InventoryItem's units on hand
    std::cout << "\nUpdating inventory...\n";
    InventoryItem updatedItem = item; // Create a copy to avoid modifying the original
    updatedItem.setUnitsOnHand(updatedItem.getUnitsOnHand() - quantity);
    updatedItem.displayItem();
}

int main() {
    InventoryItem item("Widget", 5.0, 50);
    CashRegister cashRegister;

    std::cout << "Enter the quantity of items to purchase: ";
    int quantity;
    std::cin >> quantity;

    if (quantity < 0) {
        std::cerr << "Error: Quantity cannot be negative.\n";
        return 1;
    }

    cashRegister.processPurchase(item, quantity);

    return 0;
}
