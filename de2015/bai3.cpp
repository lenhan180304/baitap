#include <iostream>
#include <vector>

// Lớp cơ sở cho các loại Sap (lớp trừu tượng)
class Sap {
protected:
    int _stt;
    float _dt;
    long _doanhThu;

public:
    static long DON_GIA_THUE;

    // Hàm ảo tính tiền thuê của mỗi loại Sap
    virtual long tinhTienThue() {
        return DON_GIA_THUE * this->_dt;
    }

    // Hàm ảo tính thuế doanh thu của mỗi loại Sap
    virtual long tinhThueDoanhThu() = 0;

    // Hàm ảo tính tổng tiền phải trả của mỗi loại Sap
    virtual long tinhTongTien() = 0;

    // Hàm ảo nhập thông tin cho mỗi loại Sap
    virtual void nhapThongTin() {
        std::cout << "Nhap STT, Dien tich, Doanh thu: ";
        std::cin >> this->_stt >> this->_dt >> this->_doanhThu;
    }

    virtual ~Sap() {
        this->_stt = 0;
        this->_dt = 0;
        this->_doanhThu = 0;
    }
};

long Sap::DON_GIA_THUE = 40000000;

// Lớp SapThucPham kế thừa từ lớp Sap
class SapThucPham : public Sap {
private:
    long _phiDongLanh;

public:
    static float PHAN_TRAM_THUE_SAP_THUC_PHAM;

    // Ghi đè hàm tính thuế doanh thu của lớp cơ sở
    long tinhThueDoanhThu() override {
        return static_cast<float>(PHAN_TRAM_THUE_SAP_THUC_PHAM) * this->_doanhThu;
    }

    // Ghi đè hàm tính tổng tiền của lớp cơ sở
    long tinhTongTien() override {
        return this->_phiDongLanh + this->tinhThueDoanhThu() + this->tinhTienThue();
    }

    // Ghi đè hàm nhập thông tin
    void nhapThongTin() override {
        Sap::nhapThongTin();
        std::cout << "Nhap phi dong lanh: ";
        std::cin >> this->_phiDongLanh;
    }
};

float SapThucPham::PHAN_TRAM_THUE_SAP_THUC_PHAM = 0.05;

// Lớp SapQuanAo kế thừa từ lớp Sap
class SapQuanAo : public Sap {
public:
    static float PHAN_TRAM_THUE_SAP_QUAN_AO;

    // Ghi đè hàm tính thuế doanh thu của lớp cơ sở
    long tinhThueDoanhThu() override {
        return static_cast<float>(PHAN_TRAM_THUE_SAP_QUAN_AO) * this->_doanhThu;
    }

    // Ghi đè hàm tính tổng tiền của lớp cơ sở
    long tinhTongTien() override {
        return this->tinhThueDoanhThu() + this->tinhTienThue();
    }
};

float SapQuanAo::PHAN_TRAM_THUE_SAP_QUAN_AO = 0.1;

// Lớp SapTrangSuc kế thừa từ lớp Sap
class SapTrangSuc : public Sap {
public:
    static long GIOI_HAN_DOANH_THU;
    static float PHAN_TRAM_THUE_DUOI_GION_HAN;
    static float PHAN_TRAM_THUE_TREN_GION_HAN;

    // Ghi đè hàm tính thuế doanh thu của lớp cơ sở
    long tinhThueDoanhThu() override {
        if (this->_doanhThu < GIOI_HAN_DOANH_THU) {
            return static_cast<float>(PHAN_TRAM_THUE_DUOI_GION_HAN) * this->_doanhThu;
        } else {
            return static_cast<float>(PHAN_TRAM_THUE_TREN_GION_HAN) * this->_doanhThu;
        }
    }

    // Ghi đè hàm tính tổng tiền của lớp cơ sở
    long tinhTongTien() override {
        return this->tinhThueDoanhThu() + this->tinhTienThue();
    }
};

long SapTrangSuc::GIOI_HAN_DOANH_THU = 100000000;
float SapTrangSuc::PHAN_TRAM_THUE_DUOI_GION_HAN = 0.2;
float SapTrangSuc::PHAN_TRAM_THUE_TREN_GION_HAN = 0.3;

// Lớp quản lý danh sách các loại Sap
class QuanLyDanhSach {
private:
    std::vector<Sap*> _ds;

public:
    // Hàm nhập thông tin cho danh sách các Sap
    void nhapThongTin() {
        std::cout << "Nhap so luong sap duoc thue: ";
        int n;
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            int choice;
            std::cout << "1-Sap Thuc Pham, 2-SapQuanAo, 3-SapTrangSuc\n";
            std::cin >> choice;

            Sap* p = nullptr;

            // Tạo đối tượng tương ứng với lựa chọn của người dùng
            if (choice == 1) {
                p = new SapThucPham();
            } else if (choice == 2) {
                p = new SapQuanAo();
            } else if (choice == 3) {
                p = new SapTrangSuc();
            } else {
                std::cout << "Nhap sai! Nhap lai!\n";
                i--;
                continue;
            }

            // Nhập thông tin cho đối tượng
            this->_ds.push_back(p);
            this->_ds[i]->nhapThongTin();
        }
    }

    // Hàm tính tổng tiền phải trả cho toàn bộ danh sách
    long tinhTongTien() {
        long sum = 0;

        for (int i = 0; i < this->_ds.size(); i++) {
            sum += this->_ds[i]->tinhTongTien();
        }

        return sum;
    }
};

int main() {
    QuanLyDanhSach ql;
    ql.nhapThongTin();

    std::cout << "Tong tien phai tra cho tat ca sap: " << ql.tinhTongTien() << std::endl;

    return 0;
}
