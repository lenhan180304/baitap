#include <iostream>
using namespace std;

int main() {
    // Variables to store weight and height
    double weight, height;

    // Ask the user for weight and height
    cout << "Enter weight (in pounds): ";
    cin >> weight;

    cout << "Enter height (in inches): ";
    cin >> height;

    // Calculate the BMI
    double bmi = (weight * 703) / (height * height);

    // Determine weight status based on BMI
    if (bmi >= 18.5 && bmi <= 25) {
        cout << "Optimal weight. You have a healthy BMI." << endl;
    } else if (bmi < 18.5) {
        cout << "Underweight. You may need to gain some weight." << endl;
    } else {
        cout << "Overweight. You may need to lose some weight." << endl;
    }

    return 0;
}
