#include <iostream>
using namespace std;

int main() 
{
    double mealCharge = 88.67;  // Số tiền hóa đơn
    double taxRate = 0.0675;  // Tỷ lệ thuế (6.75%)
    double tipRate = 0.20;  // Tỷ lệ tip (20%)

    double taxAmount = mealCharge * taxRate;  // Tính số tiền thuế
    double totalWithTax = mealCharge + taxAmount;  // Tính tổng số tiền sau khi cộng thuế
    double tipAmount = totalWithTax * tipRate;  // Tính số tiền tip
    double totalBill = totalWithTax + tipAmount;  // Tính tổng số tiền hóa đơn

    cout << "chi phi bua an: $" << mealCharge << endl;
    cout << "so tien thue: $" << taxAmount << endl;
    cout << "so tien tip: $" << tipAmount << endl;
    cout << "tong hoa don: $" << totalBill << endl;

    return 0;
}
