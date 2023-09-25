#include <iostream>
using namespace std;

int main() 
{
    double rate = 1.5;  // Tốc độ tăng mực nước biển (mm/yr)
    int years1 = 5;  // Số năm đầu tiên
    int years2 = 7;  // Số năm thứ hai
    int years3 = 10;  // Số năm thứ ba

    double elevation1 = rate * years1;  // Số milimet mực nước biển cao hơn sau 5 năm
    double elevation2 = rate * years2;  // Số milimet mực nước biển cao hơn sau 7 năm
    double elevation3 = rate * years3;  // Số milimet mực nước biển cao hơn sau 10 năm

    cout << "So milimet muc nuoc bien cao hon sau 5 nam: " << elevation1 << " mm" << endl;
    cout << "So milimet muc nuoc bien cao hon sau 7 nam: " << elevation2 << " mm" << endl;
    cout << "So milimet muc nuoc bien cao hon sau 10 nam: " << elevation3 << " mm" << endl;

    return 0;
}
