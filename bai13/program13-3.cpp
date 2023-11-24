#include <iostream>
using namespace std;

// Rectangle class declaration.
class Rectangle
{
private:
    double length;
    double width;

public:
    // Member function declarations
    void setLength(double);
    void setWidth(double);
    double getLength() const;
    double getWidth() const;
    double getArea() const;
};

// Member function definitions
void Rectangle::setLength(double len)
{
    length = len;
}

void Rectangle::setWidth(double wid)
{
    width = wid;
}

double Rectangle::getLength() const
{
    return length;
}

double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getArea() const
{
    return length * width;
}

int main()
{
    double number;
    double totalArea;
    Rectangle *kitchen = nullptr; // To point to kitchen dimensions
    Rectangle *bedroom = nullptr; // To point to bedroom dimensions
    Rectangle *den = nullptr;     // To point to den dimensions

    // Dynamically allocate the objects.
    kitchen = new Rectangle;
    bedroom = new Rectangle;
    den = new Rectangle;

    // Get the kitchen dimensions.
    cout << "What is the kitchen's length? ";
    cin >> number;
    kitchen->setLength(number);
    cout << "What is the kitchen's width? ";
    cin >> number;
    kitchen->setWidth(number);

    // Get the bedroom dimensions.
    cout << "What is the bedroom's length? ";
    cin >> number;
    bedroom->setLength(number);
    cout << "What is the bedroom's width? ";
    cin >> number;
    bedroom->setWidth(number);

    // Get the den dimensions.
    cout << "What is the den's length? ";
    cin >> number;
    den->setLength(number);
    cout << "What is the den's width? ";
    cin >> number;
    den->setWidth(number);

    // Calculate the total area of the three rooms.
    totalArea = kitchen->getArea() + bedroom->getArea() + den->getArea();

    // Display the total area of the three rooms.
    cout << "The total area of the three rooms is " << totalArea << endl;

    // Delete the objects from memory.
    delete kitchen;
    delete bedroom;
    delete den;

    kitchen = nullptr; // Make kitchen a null pointer.
    bedroom = nullptr; // Make bedroom a null pointer.
    den = nullptr;     // Make den a null pointer.

    return 0;
}
