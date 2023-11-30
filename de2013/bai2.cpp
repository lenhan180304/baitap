#include <iostream>

// Lớp cơ sở
class Base {
public:
    Base() {
        std::cout << "Constructor of Base\n";
    }

    // Hàm hủy ảo
    virtual ~Base() {
        std::cout << "Destructor of Base\n";
    }
};

// Lớp kế thừa từ lớp cơ sở
class Derived : public Base {
public:
    Derived() {
        std::cout << "Constructor of Derived\n";
    }

    // Hàm hủy (có thể bị lỗi nếu không là hàm hủy ảo)
    ~Derived() {
        std::cout << "Destructor of Derived\n";
    }
};

int main() {
    // Tạo đối tượng Derived thông qua con trỏ của lớp cơ sở
    Base* obj = new Derived();

    // Xóa đối tượng thông qua con trỏ của lớp cơ sở
    delete obj;

    return 0;
}
