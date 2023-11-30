//5 phương thức trong số các phương thức đã khai báo
#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu;  // Tử số của phân số
    int mau; // Mẫu số của phân số

public:
    // Constructor mặc định
    PhanSo() {
        this->tu = 0;
        this->mau = 1;
    }

    // Constructor với tùy chọn tử số và mẫu số
    PhanSo(const int& tu, const int& mau) {
        this->tu = tu;
        this->mau = mau;
        
        // Kiểm tra mẫu số có bằng 0 không
        if (this->mau == 0) {
            cout << "Mau khong duoc bang 0\n";
            this->tu = 0;
            this->mau = 0;
        }
    }

    // Phép cộng phân số với phân số khác
    PhanSo operator+(const PhanSo& ps) {
        PhanSo newPhanSo(this->tu * ps.mau + this->mau * ps.tu, this->mau * ps.mau);
        return newPhanSo;
    }

    // Phép cộng và gán phân số khác vào phân số hiện tại
    PhanSo operator+=(const PhanSo& ps) {
        this->tu = this->tu * ps.mau + this->mau * ps.tu;
        this->mau *= ps.mau;
        return *this;
    }

    // Phép cộng phân số với một số nguyên
    PhanSo operator+(const int& iNum) {
        PhanSo newPhanSo(this->tu + iNum * this->mau, this->mau);
        return newPhanSo;
    }

    // Phép tăng tử số của phân số lên 1
    PhanSo operator++() {
        this->tu += this->mau;
        return *this;
    }

    // Chuyển đổi phân số thành số nguyên
    operator int() {
        PhanSo newPhanSo(this->tu, 1);
        return newPhanSo.tu;
    }

    // Hàm thân thiện (friend) để xuất phân số ra màn hình
    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        os << ps.tu << "/" << ps.mau;
        return os;
    }

    // Destructor
    ~PhanSo() {
        this->tu = 0;
        this->mau = 1;
    }
};

int main() {
    // Sử dụng các phép toán trên phân số
    PhanSo ps1(1, 2), ps2(3, 4), ps3;
    
    ps3 = ps1 + ps2;
    cout << "Tong cua ps1 va ps2: " << ps3 << endl;

    ps1 += ps2;
    cout << "ps1 sau khi cong voi ps2: " << ps1 << endl;

    ps3 = ps1 + 5;
    cout << "Tong cua ps1 va 5: " << ps3 << endl;

    ++ps1;
    cout << "ps1 sau khi tang len 1: " << ps1 << endl;

    int iNum = int(ps1);  // Chuyển đổi phân số thành số nguyên
    cout << "Chuyen doi ps1 thanh so nguyen: " << iNum << endl;

    return 0;
}
