#include <iostream>
#include <fstream>
using namespace std;

const int NUM_MONTHS = 3;
const int NUM_DAYS = 30;

// Function to read weather data from a file into a 2D array
void readWeatherData(char data[NUM_MONTHS][NUM_DAYS]) {
    ifstream inputFile("RainOrShine.txt");
    if (!inputFile) {
        cerr << "Error: Could not open the file 'RainOrShine.txt'." << endl;
        exit(1);
    }

    for (int month = 0; month < NUM_MONTHS; month++) {
        for (int day = 0; day < NUM_DAYS; day++) {
            inputFile >> data[month][day];
        }
    }

    inputFile.close();
}

// Function to count rainy, cloudy, and sunny days for a specific month
void countWeatherDays(const char data[NUM_MONTHS][NUM_DAYS], char weatherType, int& count) {
    count = 0;
    for (int month = 0; month < NUM_MONTHS; month++) {
        for (int day = 0; day < NUM_DAYS; day++) {
            if (data[month][day] == weatherType) {
                count++;
            }
        }
    }
}

int main() {
    char weatherData[NUM_MONTHS][NUM_DAYS];
    readWeatherData(weatherData);

    char months[NUM_MONTHS][10] = {"June", "July", "August"};
    int rainyDays[NUM_MONTHS];
    int cloudyDays[NUM_MONTHS];
    int sunnyDays[NUM_MONTHS];

    for (int month = 0; month < NUM_MONTHS; month++) {
        countWeatherDays(weatherData, 'R', rainyDays[month]);
        countWeatherDays(weatherData, 'C', cloudyDays[month]);
        countWeatherDays(weatherData, 'S', sunnyDays[month]);
    }

    int totalRainyDays = 0;
    int largestRainyMonth = 0;

    for (int month = 0; month < NUM_MONTHS; month++) {
        cout << "Month: " << months[month] << endl;
        cout << "Rainy Days: " << rainyDays[month] << endl;
        cout << "Cloudy Days: " << cloudyDays[month] << endl;
        cout << "Sunny Days: " << sunnyDays[month] << endl;
        cout << endl;

        totalRainyDays += rainyDays[month];
        if (rainyDays[month] > rainyDays[largestRainyMonth]) {
            largestRainyMonth = month;
        }
    }

    cout << "Total Rainy Days for the Three Months: " << totalRainyDays << endl;
    cout << "Month with the Largest Number of Rainy Days: " << months[largestRainyMonth] << endl;

    return 0;
}
