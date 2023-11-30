#include <iostream>
#include <string>

// Định nghĩa interface IFace
class IFace {
public:
    virtual void show() = 0; // Phương thức ảo pure virtual
    virtual IFace* clone() = 0; // Phương thức tạo bản sao ảo pure virtual
    virtual ~IFace() {} // Hàm hủy ảo
};

// Lớp Face
class Face : public IFace {
private:
    std::string shape; // Hình dạng khuôn mặt

public:
    // Hàm khởi tạo Face với tham số mặc định là chuỗi trống
    Face(const std::string& sh = "") : shape(sh) {}

    // Phương thức hiển thị thông tin khuôn mặt
    void show() override {
        std::cout << "Shape: " << shape << std::endl;
    }

    // Phương thức tạo bản sao của Face
    IFace* clone() override {
        Face* clone = new Face(shape);
        return clone;
    }

    // Hàm hủy của Face
    ~Face() {
        shape = ""; // Xóa dữ liệu hình dạng khuôn mặt
    }
};

// Lớp EyedFace thừa kế từ IFace
class EyedFace : public IFace {
private:
    std::string shape; // Hình dạng khuôn mặt
    int eyes; // Số mắt

public:
    // Phương thức hiển thị thông tin khuôn mặt
    void show() override {
        std::cout << "Shape: " << shape << ", Eyes: " << eyes << std::endl;
    }

    // Phương thức tạo bản sao của EyedFace
    IFace* clone() override {
        EyedFace* clone = new EyedFace(shape, eyes);
        return clone;
    }

    // Hàm khởi tạo EyedFace
    EyedFace(const std::string& sh, const int& e) : shape(sh), eyes(e) {}

    // Hàm hủy của EyedFace
    ~EyedFace() {
        shape = ""; // Xóa dữ liệu hình dạng khuôn mặt
        eyes = 0;   // Đặt số mắt về 0
    }
};

int main() {
    // Tạo một đối tượng EyedFace
    EyedFace* face1 = new EyedFace("Round", 2);

    // Hiển thị thông tin khuôn mặt
    face1->show();

    // Tạo bản sao của đối tượng EyedFace
    IFace* face2 = face1->clone();

    // Hiển thị thông tin khuôn mặt của bản sao
    face2->show();

    // Giải phóng bộ nhớ
    delete face1;
    delete face2;

    return 0;
}
