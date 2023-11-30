#include <cmath>

// Lớp cơ sở cho các hàm số
class Function {
public:
    virtual double Value(double x) const = 0;    // Hàm ảo để tính giá trị hàm số
    virtual double Derive(double x) const = 0;   // Hàm ảo để tính đạo hàm hàm số
};

// Lớp con cho hàm cos
class Cos : public Function {
public:
    // Hàm tính giá trị của hàm cos tại một điểm x
    double Value(double x) const override {
        return cos(x);
    }

    // Hàm tính đạo hàm của hàm cos tại một điểm x
    double Derive(double x) const override {
        return -sin(x);
    }
};

// Hàm tính đạo hàm thương của hai hàm số f và g tại một điểm x
double DaoHamThuong(Function* f, Function* g, double x) {
    if (g != nullptr) {
        return (f->Derive(x) * g->Value(x) - f->Value(x) * g->Derive(x)) / (g->Value(x) * g->Value(x));
    }
    return 0;
}

// Hàm tính đạo hàm của hàm hợp f ∘ g tại một điểm x
double DaoHamCuaHamHop(Function* f, Function* g, double x) {
    if (f != nullptr && g != nullptr) {
        return f->Derive(g->Value(x)) * g->Derive(x);
    }
    return 0;
}
