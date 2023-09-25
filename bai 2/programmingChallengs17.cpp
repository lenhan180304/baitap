#include <iostream>
using namespace std;

int main() {
    int shares = 750;            // Số cổ phiếu mua
    float stock_price = 35.00;   // Giá mỗi cổ phiếu
    float commission_rate = 0.02; // Tỷ lệ hoa hồng

    // Tính số tiền trả cho cổ phiếu mà không kể hoa hồng
    float amount_paid_for_stock = shares * stock_price;

    // Tính số tiền hoa hồng
    float commission = amount_paid_for_stock * commission_rate;

    // Tính tổng số tiền đã trả (bao gồm cổ phiếu và hoa hồng)
    float total_amount_paid = amount_paid_for_stock + commission;

    // Hiển thị kết quả
    cout << "Amount paid for the stock alone: " << amount_paid_for_stock << endl;
    cout << "Amount of commission: " << commission << endl;
    cout << "Total amount paid: " << total_amount_paid << endl;

    return 0;
}
