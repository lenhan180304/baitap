#include <iostream>
using namespace std;

// Demo class declaration.
class Demo
{
public:
    Demo(); // Constructor declaration
};

// Constructor definition
Demo::Demo()
{
    cout << "Welcome to the constructor!\n";
}

// Function main
int main()
{
    Demo demoObject; // Create a Demo object; constructor is called

    cout << "This program demonstrates an object\n";
    cout << "with a constructor.\n";
    return 0;
}
