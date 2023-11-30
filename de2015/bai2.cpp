#include <iostream>
#include <string>

class BigInteger {
private:
    std::string _bigNum;

public:
    // Hàm khởi tạo mặc định
    BigInteger() {
        this->_bigNum = "";
    }

    // Hàm khởi tạo từ chuỗi
    BigInteger(std::string s) {
        // Loại bỏ khoảng trắng trong chuỗi số
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                for (int j = i; j < s.size(); j++) {
                    s[i] = s[i + 1];
                }
                i--;
                s[s.size() - 1] = 0;
            }
        }
        this->_bigNum = s;
    }

    // Hàm nhập số lớn từ người dùng
    friend std::istream& operator>>(std::istream& is, BigInteger& bigNum) {
        // Sử dụng getline để đọc cả dòng vừa chứa số lớn từ người dùng
        std::getline(is, bigNum._bigNum);
        return is;
    }

    // Toán tử so sánh bằng
    bool operator==(const BigInteger& bNum) {
        return this->_bigNum == bNum._bigNum;
    }
};

int main() {
    BigInteger num1, num2;
    
    // Nhập số lớn thứ nhất
    std::cout << "Enter the first big integer: ";
    std::cin >> num1;

    // Nhập số lớn thứ hai
    std::cout << "Enter the second big integer: ";
    std::cin >> num2;

    // So sánh và xuất kết quả
    if (num1 == num2) {
        std::cout << "Both big integers are equal." << std::endl;
    } else {
        std::cout << "The big integers are not equal." << std::endl;
    }

    return 0;
}
