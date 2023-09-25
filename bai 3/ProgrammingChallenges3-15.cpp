#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double ASSESSMENT_PERCENTAGE = 0.6;
    const double PROPERTY_TAX_RATE = 0.0075;

    double actualValue;

    // Ask the user for the actual value of the property
    cout << "Enter the actual value of the property: $";
    cin >> actualValue;

    // Calculate the assessment value and property tax
    double assessmentValue = actualValue * ASSESSMENT_PERCENTAGE;
    double propertyTax = assessmentValue * PROPERTY_TAX_RATE;

    // Display the assessment value and property tax
    cout << "Assessment Value: $" << fixed << setprecision(2) << assessmentValue << endl;
    cout << "Property Tax: $" << fixed << setprecision(2) << propertyTax << endl;

    return 0;
}
