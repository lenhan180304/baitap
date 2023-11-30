#include <iostream>

// Lớp cơ sở cho các hàm số
class Function {
public:
    virtual double Value(double x) const = 0;    // Hàm ảo để tính giá trị hàm số
    virtual double Derive(double x) const = 0;   // Hàm ảo để tính đạo hàm hàm số
};

// Lớp con cho hàm số hằng
class ConstantFunction : public Function {
private:
    double constant;

public:
    ConstantFunction(double c) : constant(c) {}

    double Value(double x) const override {
        return constant;
    }

    double Derive(double x) const override {
        return 0;  // Đạo hàm của hàm số hằng là 0
    }
};

// Lớp con cho hàm số đồng nhất (identity function)
class IdentityFunction : public Function {
public:
    double Value(double x) const override {
        return x;
    }

    double Derive(double x) const override {
        return 1;  // Đạo hàm của hàm số đồng nhất là 1
    }
};

// Lớp con cho hàm thương
class QuotientFunction : public Function {
private:
    Function* f;
    Function* g;

public:
    QuotientFunction(Function* f, Function* g) : f(f), g(g) {}

    double Value(double x) const override {
        return f->Value(x) / g->Value(x);
    }

    double Derive(double x) const override {
        return (f->Derive(x) * g->Value(x) - f->Value(x) * g->Derive(x)) / (g->Value(x) * g->Value(x));
    }
};

// Lớp con cho hàm hợp
class CompositeFunction : public Function {
private:
    Function* f;
    Function* g;

public:
    CompositeFunction(Function* f, Function* g) : f(f), g(g) {}

    double Value(double x) const override {
        return f->Value(g->Value(x));
    }

    double Derive(double x) const override {
        return f->Derive(g->Value(x)) * g->Derive(x);
    }
};

int main() {
    // Tạo đối tượng hàm thương f(x) = x^2 và g(x) = x + 1
    Function* f = new CompositeFunction(new QuotientFunction(new ConstantFunction(1.0), new IdentityFunction()), new IdentityFunction());

    // Tính giá trị và đạo hàm của hàm thương tại một điểm x
    double x = 2.0;
    double resultValue = f->Value(x);
    double resultDerivative = f->Derive(x);

    // Hiển thị kết quả
    std::cout << "Gia tri cua ham thuonng tai x = " << x << " la: " << resultValue << std::endl;
    std::cout << "Dao ham cua ham thuong tai x = " << x << " la: " << resultDerivative << std::endl;

    delete f;  // Giải phóng bộ nhớ

    return 0;
}
