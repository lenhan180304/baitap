#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int numMales, numFemales;
    int totalStudents;
    double malePercentage, femalePercentage;

    // Ask the user for the number of males and females
    cout << "Enter the number of males in the class: ";
    cin >> numMales;
    cout << "Enter the number of females in the class: ";
    cin >> numFemales;

    // Calculate the total number of students
    totalStudents = numMales + numFemales;

    // Calculate the percentage of males and females
    malePercentage = static_cast<double>(numMales) / totalStudents * 100;
    femalePercentage = static_cast<double>(numFemales) / totalStudents * 100;

    // Display the percentage of males and females
    cout << fixed << setprecision(1);
    cout << "The percentage of males in the class is: " << malePercentage << "%" << endl;
    cout << "The percentage of females in the class is: " << femalePercentage << "%" << endl;

    return 0;
}
