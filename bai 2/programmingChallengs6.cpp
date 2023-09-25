#include <iostream>
using namespace std;

int main() 
{
    double payAmount = 2200.0;  // Số tiền lương hàng kỳ
    int payPeriods = 26;  // Số kỳ lương trong năm
    double annualPay = payAmount * payPeriods;  // Tính tổng lương hàng năm

    cout << "tong luong hang nam: $" << annualPay << endl;

    return 0;
}
