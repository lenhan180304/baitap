#include <iostream>

// Lớp trừu tượng Shape
class Shape {
public:
    // Phương thức thuần ảo area, không có triển khai ở đây
    virtual double area() const = 0;

    // Phương thức thông thường
    void displayArea() const {
        std::cout << "Area: " << area() << std::endl;
    }
};

// Lớp con Rectangle kế thừa từ lớp trừu tượng Shape
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Triển khai lại phương thức area của lớp cơ sở
    double area() const override {
        return width * height;
    }
};

// Lớp con Circle kế thừa từ lớp trừu tượng Shape
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Triển khai lại phương thức area của lớp cơ sở
    double area() const override {
        return 3.14 * radius * radius;
    }
};

int main() {
    // Không thể tạo đối tượng từ lớp trừu tượng Shape
    // Shape shape; // Lỗi

    // Tạo đối tượng hình chữ nhật và hình tròn
    Rectangle rectangle(5, 10);
    Circle circle(7);

    // Gọi phương thức area thông qua đối tượng của lớp con
    rectangle.displayArea();
    circle.displayArea();

    return 0;
}
