#include <cmath>

class Sin {
private:
    static Sin* instance; // Đối tượng duy nhất của lớp Sin
    Sin() {} // Hàm khởi tạo private để ngăn chặn tạo đối tượng từ bên ngoài

public:
    // Hàm để lấy đối tượng duy nhất của lớp Sin
    static Sin* getInstance() {
        if (instance == nullptr) {
            instance = new Sin();
        }
        return instance;
    }

    // Hàm tính giá trị của hàm sin
    double calculate(double x) const {
        return sin(x);
    }

    // Hàm hủy (destructor) để giải phóng bộ nhớ khi chương trình kết thúc
    ~Sin() {
        delete instance;
    }
};

// Khởi tạo đối tượng instance tại đây
Sin* Sin::instance = nullptr;

int main() {
    // Sử dụng hàm sin thông qua đối tượng duy nhất của lớp Sin
    double result = Sin::getInstance()->calculate(3.14);

    // Rest of the program...

    return 0;
}
