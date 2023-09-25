#include <iostream>

using namespace std;

int main() {
    double totalSales = 8600000.0;  // Tổng doanh thu bằng đô la
    double eastCoastPercentage = 0.58;  // Tỷ lệ doanh thu được tạo ra bởi the East Coast division

    double eastCoastSales = totalSales * eastCoastPercentage;  // Tính toán doanh số bán hàng ở East Coast

    cout << "The East Coast division is predicted to generate: $" << eastCoastSales << " million" << endl;

    return 0;
}
