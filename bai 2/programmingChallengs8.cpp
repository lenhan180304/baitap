#include <iostream>
using namespace std;

int main() 
{
    double item1 = 15.95;  // Giá của món hàng thứ nhất
    double item2 = 24.95;  // Giá của món hàng thứ hai
    double item3 = 6.95;   // Giá của món hàng thứ ba
    double item4 = 12.95;  // Giá của món hàng thứ tư
    double item5 = 3.95;   // Giá của món hàng thứ năm

    double subtotal = item1 + item2 + item3 + item4 + item5;  // Tổng giá trị của các mặt hàng
    double taxRate = 0.07;  // Tỷ lệ thuế suất (7%)
    double salesTax = subtotal * taxRate;  // Số tiền thuế phải trả
    double total = subtotal + salesTax;  // Tổng số tiền phải trả

    cout << "Gia mat hang:" << endl;
    cout << "Mat hang 1: $" << item1 << endl;
    cout << "Mat hang 2: $" << item2 << endl;
    cout << "Mat hang 3: $" << item3 << endl;
    cout << "Mat hang 4: $" << item4 << endl;
    cout << "Mat hang 5: $" << item5 << endl;
    cout << "----------------------------" << endl;
    cout << "Tong tien hang: $" << subtotal << endl;
    cout << "So tien thue: $" << salesTax << endl;
    cout << "Tong cong: $" << total << endl;

    return 0;
}
