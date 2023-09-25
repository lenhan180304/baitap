#include <iostream>
using namespace std;

int main() 
{
    double totalPurchaseAmount = 95.0;  // Tổng số tiền mua hàng trong đô la
    double stateSalesTaxRate = 0.04;  // Tỷ lệ thuế bán hàng của tiểu bang (4%)
    double countySalesTaxRate = 0.02;  // Tỷ lệ thuế bán hàng của quận (2%)

    double stateSalesTax = totalPurchaseAmount * stateSalesTaxRate;  // Tính thuế bán hàng của tiểu bang
    double countySalesTax = totalPurchaseAmount * countySalesTaxRate;  // Tính thuế bán hàng của quận
    double totalSalesTax = stateSalesTax + countySalesTax;  // Tính tổng thuế bán hàng

    cout << "tong so tien thue ban hang tren moi $" << totalPurchaseAmount << " la: $" << totalSalesTax << endl;

    return 0;
}
