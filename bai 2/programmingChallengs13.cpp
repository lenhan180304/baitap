#include <iostream>
using namespace std;

int main() 
{
    double cost = 14.95;
    double profitPercentage = 0.35;

    // Tính toán giá bán của bo mạch điện
    double sellingPrice = cost + (cost * profitPercentage);

    // Hiển thị kết quả giá bán trên màn hình
    cout << "The selling price of the circuit board is $" << sellingPrice << endl;

    return 0;
}
