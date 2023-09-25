#include <iostream>
using namespace std;

int main() {
    int total_customers = 16500;
    float energy_drink_percentage = 0.15;
    float citrus_flavored_percentage = 0.58;

    // Tính số khách hàng xấp xỉ mua một hoặc nhiều lon nước giải khát mỗi tuần
    float num_energy_drink_customers = total_customers * energy_drink_percentage;

    // Tính số khách hàng xấp xỉ ưa thích loại nước giải khát có mùi cam
    float num_citrus_flavored_customers = num_energy_drink_customers * citrus_flavored_percentage;

    // Hiển thị kết quả
    cout << "Approximate number of customers who purchase one or more energy drinks per week: " << num_energy_drink_customers << endl;
    cout << "Approximate number of customers who prefer citrus-flavored energy drinks: " << num_citrus_flavored_customers << endl;

    return 0;
}
