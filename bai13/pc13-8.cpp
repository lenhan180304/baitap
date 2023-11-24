#include <iostream>
#include <cmath>

class Circle {
private:
    double radius;
    const double pi;

public:
    // Constructors
    Circle();
    explicit Circle(double r);

    // Mutator and accessor functions
    void setRadius(double r);
    double getRadius() const;

    // Calculations
    double getArea() const;
    double getDiameter() const;
    double getCircumference() const;
};

// Default constructor
Circle::Circle() : radius(0.0), pi(3.14159) {}

// Constructor with radius parameter
Circle::Circle(double r) : radius(r), pi(3.14159) {}

// Mutator function for radius
void Circle::setRadius(double r) {
    radius = r;
}

// Accessor function for radius
double Circle::getRadius() const {
    return radius;
}

// Calculate area of the circle
double Circle::getArea() const {
    return pi * radius * radius;
}

// Calculate diameter of the circle
double Circle::getDiameter() const {
    return radius * 2;
}

// Calculate circumference of the circle
double Circle::getCircumference() const {
    return 2 * pi * radius;
}

int main() {
    // Demonstrate the Circle class
    double userRadius;

    // Get the radius from the user
    std::cout << "Enter the radius of the circle: ";
    std::cin >> userRadius;

    // Create a Circle object
    Circle myCircle(userRadius);

    // Display the circle's properties
    std::cout << "Area: " << myCircle.getArea() << std::endl;
    std::cout << "Diameter: " << myCircle.getDiameter() << std::endl;
    std::cout << "Circumference: " << myCircle.getCircumference() << std::endl;

    return 0;
}
