#include <iostream>
using namespace std;

int main() 
{

    // Khai báo biến diện tích trong feet vuông
    double areaInSquareFeet = 391876;

    // Tính toán số acre bằng cách chia diện tích trong feet vuông cho 43,560
    double numberOfAcres = areaInSquareFeet / 43560;

    // Hiển thị kết quả số acre
    cout << "The tract of land is approximately " << numberOfAcres << " acre." << endl;

    return 0;
}
