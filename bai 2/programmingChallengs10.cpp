#include <iostream>
using namespace std;

int main() 
{
    int milesDriven = 375; // Số dặm đã đi được
    int gallonsUsed = 15; // Số gallon xăng đã sử dụng

    double mpg = (double) milesDriven / gallonsUsed;

    cout << "Xe duoc " << mpg << " dam tren moi gallon xang." << endl;

    return 0;
}
