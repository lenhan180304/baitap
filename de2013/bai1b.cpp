#include <iostream>

class A_B_Sqrt_X {
private:
    int _a;
    int _b;
    int _SO_DUOI_DAU_CAN; // Số dưới dấu căn, có thể hiểu là "x" trong b√x

public:
    // Hàm khởi tạo
    A_B_Sqrt_X(int a, int b, int soDuoiDauCan) : _a(a), _b(b), _SO_DUOI_DAU_CAN(soDuoiDauCan) {}

    // Toán tử cộng
    A_B_Sqrt_X operator+(const A_B_Sqrt_X& other) {
        return A_B_Sqrt_X(_a + other._a, _b + other._b, _SO_DUOI_DAU_CAN + other._SO_DUOI_DAU_CAN);
    }

    // Toán tử trừ
    A_B_Sqrt_X operator-(const A_B_Sqrt_X& other) {
        return A_B_Sqrt_X(_a - other._a, _b - other._b, _SO_DUOI_DAU_CAN - other._SO_DUOI_DAU_CAN);
    }

    // Toán tử đảo dấu
    A_B_Sqrt_X operator-() {
        return A_B_Sqrt_X(-_a, -_b, -_SO_DUOI_DAU_CAN);
    }

    // Toán tử nhân
    A_B_Sqrt_X operator*(const A_B_Sqrt_X& other) {
        int resultA = _a * other._a + _b * other._b * _SO_DUOI_DAU_CAN;
        int resultB = _a * other._b + _b * other._a;

        return A_B_Sqrt_X(resultA, resultB, _SO_DUOI_DAU_CAN);
    }

    // Toán tử xuất
    friend std::ostream& operator<<(std::ostream& os, const A_B_Sqrt_X& num) {
        os << num._a << " + " << num._b << "√" << num._SO_DUOI_DAU_CAN;
        return os;
    }

    // Toán tử nhập
    friend std::istream& operator>>(std::istream& is, A_B_Sqrt_X& num) {
        is >> num._a >> num._b >> num._SO_DUOI_DAU_CAN;
        return is;
    }
};

int main() {
    // Khởi tạo và sử dụng các toán tử
    A_B_Sqrt_X num1(2, 3, 7);
    A_B_Sqrt_X num2(1, -2, 7);

    A_B_Sqrt_X sum = num1 + num2;
    A_B_Sqrt_X difference = num1 - num2;
    A_B_Sqrt_X negation = -num1;
    A_B_Sqrt_X product = num1 * num2;

    // Hiển thị kết quả
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Negation: " << negation << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}
