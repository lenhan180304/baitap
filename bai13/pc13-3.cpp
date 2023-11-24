#include <iostream>
#include <string>

class Car {
private:
    int yearModel;
    std::string make;
    int speed;

public:
    // Constructor
    Car(int year, const std::string& carMake);

    // Accessor functions
    int getYearModel() const;
    std::string getMake() const;
    int getSpeed() const;

    // Member functions
    void accelerate();
    void brake();
};

// Constructor
Car::Car(int year, const std::string& carMake) : yearModel(year), make(carMake), speed(0) {}

// Accessor functions
int Car::getYearModel() const {
    return yearModel;
}

std::string Car::getMake() const {
    return make;
}

int Car::getSpeed() const {
    return speed;
}

// Accelerate function
void Car::accelerate() {
    speed += 5;
}

// Brake function
void Car::brake() {
    speed -= 5;
    if (speed < 0) {
        speed = 0; // Ensure speed is non-negative
    }
}

int main() {
    // Create a Car object
    Car myCar(2022, "Toyota");

    // Accelerate the car five times
    for (int i = 0; i < 5; ++i) {
        myCar.accelerate();
        std::cout << "Current speed after acceleration: " << myCar.getSpeed() << " mph\n";
    }

    // Brake the car five times
    for (int i = 0; i < 5; ++i) {
        myCar.brake();
        std::cout << "Current speed after braking: " << myCar.getSpeed() << " mph\n";
    }

    return 0;
}
