#include <iostream>

class Singleton {
private:
    static Singleton* instance;  // Thể hiện duy nhất của Singleton

    // Hạn chế khả năng tạo ra đối tượng từ bên ngoài
    Singleton() {
        // Khởi tạo đối tượng
    }

public:
    // Phương thức để truy cập thể hiện duy nhất
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();  // Tạo đối tượng nếu chưa tồn tại
        }
        return instance;
    }

    // Các phương thức khác của lớp

    void someMethod() {
        std::cout << "Calling some method in Singleton\n";
    }
};

// Khởi tạo đối tượng instance
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* obj1 = Singleton::getInstance();
    obj1->someMethod();

    Singleton* obj2 = Singleton::getInstance();

    // Đối tượng obj2 sẽ trỏ đến cùng một thể hiện mà obj1
    obj2->someMethod();

    // Kết thúc chương trình, nhớ giải phóng bộ nhớ
    delete obj1;

    return 0;
}
