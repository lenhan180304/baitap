#include <iostream>
using namespace std;

// Class declaration
class Demo {
public:
    // Constructor
    Demo();

    // Destructor
    ~Demo();
};

// Constructor definition
Demo::Demo() {
    cout << "Welcome to the constructor!\n";
}

// Destructor definition
Demo::~Demo() {
    cout << "The destructor is now running.\n";
}

// Function main
int main() {
    // Create a Demo object
    Demo demoObject;

    // Display a message
    cout << "This program demonstrates an object\n";
    cout << "with a constructor and destructor.\n";

    return 0;
}
