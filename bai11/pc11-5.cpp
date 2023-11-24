#include <iostream>
#include <string>

using namespace std;

// Enumerated data type for months
enum Month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

// Structure to store weather data for a month
struct WeatherData {
    double totalRainfall;
    double highTemperature;
    double lowTemperature;
    double averageTemperature;
};

// Function to input weather data for a month
void inputWeatherData(WeatherData& month) {
    // Input total rainfall
    cout << "Enter total rainfall for the month: ";
    cin >> month.totalRainfall;

    // Input high temperature, validating for the temperature range
    do {
        cout << "Enter high temperature for the month (between -100 and 140 degrees Fahrenheit): ";
        cin >> month.highTemperature;
    } while (month.highTemperature < -100 || month.highTemperature > 140);

    // Input low temperature, validating for the temperature range
    do {
        cout << "Enter low temperature for the month (between -100 and 140 degrees Fahrenheit): ";
        cin >> month.lowTemperature;
    } while (month.lowTemperature < -100 || month.lowTemperature > 140);

    // Calculate average temperature
    month.averageTemperature = (month.highTemperature + month.lowTemperature) / 2.0;
}

int main() {
    const int numMonths = 12;
    WeatherData yearlyData[numMonths];

    // Input weather data for each month using the enumerated type
    for (int i = JANUARY; i <= DECEMBER; ++i) {
        cout << "\nEnter weather data for " << static_cast<Month>(i) << ":\n";
        inputWeatherData(yearlyData[i]);
    }

    // Calculate and display statistics
    double totalYearlyRainfall = 0.0;
    double totalAverageTemperature = 0.0;
    double highestTemperature = yearlyData[JANUARY].highTemperature;
    double lowestTemperature = yearlyData[JANUARY].lowTemperature;
    Month highestMonth = JANUARY;
    Month lowestMonth = JANUARY;

    for (int i = JANUARY; i <= DECEMBER; ++i) {
        totalYearlyRainfall += yearlyData[i].totalRainfall;
        totalAverageTemperature += yearlyData[i].averageTemperature;

        // Check for highest temperature
        if (yearlyData[i].highTemperature > highestTemperature) {
            highestTemperature = yearlyData[i].highTemperature;
            highestMonth = static_cast<Month>(i);
        }

        // Check for lowest temperature
        if (yearlyData[i].lowTemperature < lowestTemperature) {
            lowestTemperature = yearlyData[i].lowTemperature;
            lowestMonth = static_cast<Month>(i);
        }
    }

    // Calculate averages
    double averageMonthlyRainfall = totalYearlyRainfall / numMonths;
    double averageYearlyTemperature = totalAverageTemperature / numMonths;

    // Display statistics
    cout << "\nWeather Statistics for the Year:\n";
    cout << "Average Monthly Rainfall: " << averageMonthlyRainfall << " inches\n";
    cout << "Total Yearly Rainfall: " << totalYearlyRainfall << " inches\n";
    cout << "Highest Temperature: " << highestTemperature << " degrees Fahrenheit (Month: " << highestMonth + 1 << ")\n";
    cout << "Lowest Temperature: " << lowestTemperature << " degrees Fahrenheit (Month: " << lowestMonth + 1 << ")\n";
    cout << "Average of Monthly Average Temperatures: " << averageYearlyTemperature << " degrees Fahrenheit\n";

    return 0;
}
