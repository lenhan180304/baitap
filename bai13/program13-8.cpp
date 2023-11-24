#include <iostream>
#include <iomanip>
#include "Rectangle.h"

int main() {
    double houseWidth, houseLength;

    std::cout << "In feet, how wide is your house? ";
    std::cin >> houseWidth;

    std::cout << "In feet, how long is your house? ";
    std::cin >> houseLength;

    Rectangle house(houseWidth, houseLength);

    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "The house is " << house.getWidth() << " feet wide.\n";
    std::cout << "The house is " << house.getLength() << " feet long.\n";
    std::cout << "The house is " << house.getArea() << " square feet in area.\n";

    return 0;
}
