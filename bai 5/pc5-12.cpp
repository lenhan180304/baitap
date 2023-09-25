#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Celsius to Fahrenheit Conversion Table" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    // Display table headers
    std::cout << "Celsius\tFahrenheit" << std::endl;

    // Calculate and display the conversion for Celsius temperatures 0-20
    for (int celsius = 0; celsius <= 20; ++celsius) {
        double fahrenheit = (celsius * 9.0/5.0) + 32.0;
        std::cout << celsius << "\t" << std::fixed << std::setprecision(2) << fahrenheit << std::endl;
    }

    return 0;
}
