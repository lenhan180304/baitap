#include <iostream>
#include <string>

using namespace std;

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

    // Input weather data for each month
    for (int i = 0; i < numMonths; ++i) {
        cout << "\nEnter weather data for month " << (i + 1) << ":\n";
        inputWeatherData(yearlyData[i]);
    }

    // Calculate and display statistics
    double totalYearlyRainfall = 0.0;
    double totalAverageTemperature = 0.0;
    double highestTemperature = yearlyData[0].highTemperature;
    double lowestTemperature = yearlyData[0].lowTemperature;
    int highestMonth = 1;
    int lowestMonth = 1;

    for (int i = 0; i < numMonths; ++i) {
        totalYearlyRainfall += yearlyData[i].totalRainfall;
        totalAverageTemperature += yearlyData[i].averageTemperature;

        // Check for highest temperature
        if (yearlyData[i].highTemperature > highestTemperature) {
            highestTemperature = yearlyData[i].highTemperature;
            highestMonth = i + 1;
        }

        // Check for lowest temperature
        if (yearlyData[i].lowTemperature < lowestTemperature) {
            lowestTemperature = yearlyData[i].lowTemperature;
            lowestMonth = i + 1;
        }
    }

    // Calculate averages
    double averageMonthlyRainfall = totalYearlyRainfall / numMonths;
    double averageYearlyTemperature = totalAverageTemperature / numMonths;

    // Display statistics
    cout << "\nWeather Statistics for the Year:\n";
    cout << "Average Monthly Rainfall: " << averageMonthlyRainfall << " inches\n";
    cout << "Total Yearly Rainfall: " << totalYearlyRainfall << " inches\n";
    cout << "Highest Temperature: " << highestTemperature << " degrees Fahrenheit (Month: " << highestMonth << ")\n";
    cout << "Lowest Temperature: " << lowestTemperature << " degrees Fahrenheit (Month: " << lowestMonth << ")\n";
    cout << "Average of Monthly Average Temperatures: " << averageYearlyTemperature << " degrees Fahrenheit\n";

    return 0;
}
