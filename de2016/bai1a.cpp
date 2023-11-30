#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const double PI = 3.1415928;

class Shape {
public:
    Shape() {
        cout << "Construct Shape" << endl;
    }

    virtual string Description() {
        stringstream ss;
        ss << "Shape(area=" << this->Area() << ")";
        return ss.str();
    }

    virtual float Area() = 0;
    virtual void Scale(float scaleFactor) = 0;

    virtual ~Shape() {
        cout << "Destruct Shape" << endl;
    }
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : Shape(), radius(r) {
        cout << "Construct Circle" << endl;
    }

    string Description() override {
        stringstream ss;
        ss << "Circle(r=" << this->radius << ")";
        return ss.str();
    }

    float Area() override {
        return PI * radius * radius;
    }

    void Scale(float scaleFactor) override {
        this->radius *= scaleFactor;
    }

    ~Circle() {
        cout << "Destruct Circle" << endl;
    }
};

class Ellipse : public Shape {
private:
    float majorR, minorR;

public:
    Ellipse(float a, float b) : Shape(), majorR(a), minorR(b) {
        cout << "Construct Ellipse" << endl;
    }

    string Description() override {
        stringstream ss;
        ss << "Ellipse(a=" << this->majorR << ", b=" << this->minorR << ")";
        return ss.str();
    }

    float Area() override {
        return PI * majorR * minorR;
    }

    void Scale(float scaleFactor) override {
        this->majorR *= scaleFactor;
        this->minorR *= scaleFactor;
    }

    void Scale(float sa, float sb) {
        this->majorR *= sa;
        this->minorR *= sb;
    }

    ~Ellipse() {
        cout << "Destruct Ellipse" << endl;
    }
};

int main() {
    Ellipse ellipse(2.0 / 3, 6);
    Shape* shape = &ellipse;
    shape->Scale(1.0 / 2);

    cout << "Ellipse: " << endl;
    cout << ellipse.Description() << endl;
    cout << ellipse.Area() << endl;

    cout << "Shape = &Ellipse: " << endl;
    cout << shape->Description() << endl;
    cout << shape->Area() << endl;

    return 0;
}
