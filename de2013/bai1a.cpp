#include<iostream>
#include<cmath>

using namespace std;

class A_B_Sqrt_X {
private:
    int _a;
    int _b;
    int _SO_DUOI_DAU_CAN;

public:
    // Phương thức cộng hai đối tượng A_B_Sqrt_X
    A_B_Sqrt_X operator+(const A_B_Sqrt_X&);

    // Phương thức trừ hai đối tượng A_B_Sqrt_X
    A_B_Sqrt_X operator-(const A_B_Sqrt_X&);

    // Phương thức đảo dấu của đối tượng A_B_Sqrt_X
    A_B_Sqrt_X operator-();

    // Phương thức nhân hai đối tượng A_B_Sqrt_X
    A_B_Sqrt_X operator*(const A_B_Sqrt_X&);

    // Toán tử xuất dữ liệu ra màn hình
    friend ostream& operator<<(ostream&, const A_B_Sqrt_X&);

    // Toán tử nhập dữ liệu từ bàn phím
    friend istream& operator>>(istream&, A_B_Sqrt_X&);
};

