#include <iostream>
#include "Rectangle.h"

int main() {
    Rectangle box;
    double rectWidth, rectLength;

    std::cout << "This program will calculate the area of a rectangle.\n";
    std::cout << "Enter the width: ";
    std::cin >> rectWidth;
    std::cout << "Enter the length: ";
    std::cin >> rectLength;

    box.setWidth(rectWidth);
    box.setLength(rectLength);

    std::cout << "Here is the rectangle's data:\n";
    std::cout << "Width: " << box.getWidth() << std::endl;
    std::cout << "Length: " << box.getLength() << std::endl;
    std::cout << "Area: " << box.getArea() << std::endl;

    return 0;
}

