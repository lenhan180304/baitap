#include <iostream>
using namespace std;
#include <cstring>

class Bike {
private:
    char* brand; // Hiệu xe
public:
    // Phương thức khởi tạo mặc định của lớp Bike
    Bike() {
        char s[5] = "Bike";
        this->brand = new char[5];
        for (int i = 0; i < 5; i++) {
            this->brand[i] = s[i];
        }
    }

    // Phương thức khởi tạo của lớp Bike với tham số là chuỗi s
    Bike(char s[]) {
        this->brand = new char[strlen(s) + 1];
        for (int i = 0; i < strlen(s); i++) {
            this->brand[i] = s[i];
        }
        this->brand[strlen(s)] = '\0';
    }

    // Phương thức hủy của lớp Bike
    ~Bike() {
        if (this->brand) {
            delete[] this->brand;
        }
    }

    // Phương thức di chuyển của lớp Bike
    virtual void move(int t1) {
        cout << brand << ":" << t1 * 12 << " ";
    }
};

class EBike : public Bike {
public:
    // Phương thức di chuyển của lớp EBike
    void move(int t2) override {
        Bike::move(t2 * 2);
    }
};

// Hàm hiển thị di chuyển của các đối tượng
void display(Bike& a, EBike& b) {
    a.move(2);
    b.move(2);
}

int main() {
    EBike b1, b2;
    display(b1, b2);
    return 0;
}
