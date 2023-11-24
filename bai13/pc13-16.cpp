#include <iostream>
#include <string>

class Temperature {
private:
    double temperature;

public:
    Temperature();
    Temperature(double temp);
    void setTemperature(double temp);
    bool isEthylFreezing() const;
    bool isEthylBoiling() const;
    bool isOxygenFreezing() const;
    bool isOxygenBoiling() const;
    bool isWaterFreezing() const;
    bool isWaterBoiling() const;
};

Temperature::Temperature() : temperature(0.0) {}

Temperature::Temperature(double temp) : temperature(temp) {}

void Temperature::setTemperature(double temp) {
    temperature = temp;
}

bool Temperature::isEthylFreezing() const {
    return temperature <= -173;
}

bool Temperature::isEthylBoiling() const {
    return temperature >= 172;
}

bool Temperature::isOxygenFreezing() const {
    return temperature <= -362;
}

bool Temperature::isOxygenBoiling() const {
    return temperature >= -306;
}

bool Temperature::isWaterFreezing() const {
    return temperature <= 32;
}

bool Temperature::isWaterBoiling() const {
    return temperature >= 212;
}

int main() {
    double userTemperature;

    std::cout << "Enter a temperature: ";
    std::cin >> userTemperature;

    Temperature userTemp(userTemperature);

    std::cout << "Substances that will freeze at " << userTemperature << " degrees:\n";
    if (userTemp.isEthylFreezing()) std::cout << "Ethyl Alcohol\n";
    if (userTemp.isOxygenFreezing()) std::cout << "Oxygen\n";
    if (userTemp.isWaterFreezing()) std::cout << "Water\n";

    std::cout << "Substances that will boil at " << userTemperature << " degrees:\n";
    if (userTemp.isEthylBoiling()) std::cout << "Ethyl Alcohol\n";
    if (userTemp.isOxygenBoiling()) std::cout << "Oxygen\n";
    if (userTemp.isWaterBoiling()) std::cout << "Water\n";

    return 0;
}
