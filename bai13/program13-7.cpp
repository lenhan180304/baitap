#include <iostream>
#include "Rectangle.h" // Needed for Rectangle class

int main() {
    Rectangle box; // Define an instance of the Rectangle class

    // Display the rectangle's data.
    std::cout << "Here is the rectangle's data:\n";
    std::cout << "Width: " << box.getWidth() << std::endl;
    std::cout << "Length: " << box.getLength() << std::endl;
    std::cout << "Area: " << box.getArea() << std::endl;

    return 0;
}
