#include <iostream>

// Định nghĩa lớp cơ sở Shape
class Shape {
public:
    virtual void area() const {
        std::cout << "Area of Shape" << std::endl;
    }
};

// Lớp con Rectangle kế thừa từ lớp Shape
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Triển khai lại phương thức area của lớp cơ sở
    void area() const override {
        std::cout << "Area of Rectangle: " << width * height << std::endl;
    }
};

// Lớp con Circle kế thừa từ lớp Shape
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Triển khai lại phương thức area của lớp cơ sở
    void area() const override {
        std::cout << "Area of Circle: " << 3.14 * radius * radius << std::endl;
    }
};

// Hàm sử dụng đa hình
void printArea(const Shape& shape) {
    shape.area();
}

int main() {
    // Tạo đối tượng hình chữ nhật và hình tròn
    Rectangle rectangle(5, 10);
    Circle circle(7);

    // Gọi hàm sử dụng đa hình
    printArea(rectangle);  // In diện tích của hình chữ nhật
    printArea(circle);     // In diện tích của hình tròn

    return 0;
}
