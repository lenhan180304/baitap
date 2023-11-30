#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lớp cơ sở
class BenhNhan {
protected:
    int MSBN;

public:
    // Hàm nhập dữ liệu ảo
    virtual void nhap(istream& is) {
        is >> this->MSBN;
    }

    // Hàm cập nhật ngày xuất viện (ảo)
    virtual void capNhatNgayXuatVien(int ngay) {}

    // Hàm lấy trạng thái (ảo)
    virtual bool getTrangThai() {
        return true;
    }

    // Hàm tính tiền (ảo)
    virtual long tinhTien() {
        return 0;
    }

    // Hàm cập nhật viện phí (ảo)
    virtual void capNhatVienPhi() {}
};

// Lớp con của BenhNhan cho bệnh nhân ngoại trú
class BenhNhanNgoaiTru : public BenhNhan {
private:
    long _vienPhi;

public:
    // Constructor
    BenhNhanNgoaiTru(int id) {
        this->MSBN = id;
    }

    // Hàm nhập dữ liệu cho bệnh nhân ngoại trú
    void nhap(istream& is) override {
        is >> this->_vienPhi;
    }

    // Hàm tính tiền cho bệnh nhân ngoại trú
    long tinhTien() override {
        return this->_vienPhi;
    }

    // Hàm cập nhật viện phí cho bệnh nhân ngoại trú
    void capNhatVienPhi(long Tien) {
        this->_vienPhi += Tien;
    }
};

// Lớp con của BenhNhan cho bệnh nhân nội trú
class BenhNhanNoiTru : public BenhNhan {
private:
    int _loaiPhong;            // a=1, b=2, c=3
    int _ngayBatDauNamVien;
    int _soNgayNamVien;
    bool _daXuatVien;           // true: đã xuất viện, false: chưa

    long _phiKhamBenhMoiNgay;   // Phí khám bệnh mỗi ngày

public:
    // Các giá trị tiêu chuẩn cho loại phòng A, B, C
    static long A;
    static long B;
    static long C;

    // Hàm nhập dữ liệu cho bệnh nhân nội trú
    void nhap(istream& is) override {
        is >> this->_phiKhamBenhMoiNgay;
        char c;
        is >> c;
        this->_loaiPhong = c - 64;
    }

    // Constructor
    BenhNhanNoiTru(int MaSo, int ngay, long tien, char c) {
        this->MSBN = MaSo;
        this->_ngayBatDauNamVien = ngay;
        this->_phiKhamBenhMoiNgay = tien;
        this->_loaiPhong = c - 64;
        this->_daXuatVien = false;
    }

    // Hàm cập nhật ngày xuất viện cho bệnh nhân nội trú
    void capNhatNgayXuatVien(int ngay) override {
        this->_soNgayNamVien = ngay - this->_ngayBatDauNamVien;
        this->_daXuatVien = true;
    }

    // Hàm tính tiền cho bệnh nhân nội trú
    long tinhTien() override {
        if (this->_loaiPhong == 1) {
            return this->A * (this->_soNgayNamVien + this->_phiKhamBenhMoiNgay);
        } else if (this->_loaiPhong == 2) {
            return this->B * (this->_soNgayNamVien + this->_phiKhamBenhMoiNgay);
        } else if (this->_loaiPhong == 3) {
            return this->C * (this->_soNgayNamVien + this->_phiKhamBenhMoiNgay);
        } else {
            return 0;
        }
    }
};

// Khởi tạo giá trị tiêu chuẩn cho loại phòng A, B, C
long BenhNhanNoiTru::A = 1400000;
long BenhNhanNoiTru::B = 900000;
long BenhNhanNoiTru::C = 600000;

// Lớp quản lý danh sách bệnh nhân
class DanhSachBenhNhan {
private:
    vector<BenhNhan*> _ds;

public:
    // Hàm nhập danh sách bệnh nhân từ file input.log
    void nhap() {
        freopen("input.log", "rt", stdin);
        int ngay = 0;
        while (!cin.eof()) {
            cin >> ngay;
            int MaSo = 0;
            cin >> MaSo;
            cin.ignore();
            cin.clear();
            string s = "";
            cin >> s;
            BenhNhan* p = NULL;
            if (s == "KB") {
                long Tien = 0;
                cin >> Tien;
                if (MaSo <= this->_ds.size() - 1) {
                    this->_ds[MaSo - 1]->capNhatVienPhi();
                } else {
                    p = new BenhNhanNgoaiTru(MaSo);
                    this->_ds.push_back(p);
                }
            } else if (s == "NV") {
                long Tien = 0;
                cin >> Tien;
                char c;
                cin >> c;
                p = new BenhNhanNoiTru(MaSo, ngay, Tien, c);
                this->_ds.push_back(p);
            } else if (s == "XV") {
                this->_ds[MaSo - 1]->capNhatNgayXuatVien(ngay);
            } else if (s == "TKVP") {
                for (int i = 0; i < this->_ds.size(); i++) {
                    if (dynamic_cast<BenhNhanNgoaiTru*>(this->_ds[i]) == NULL) {
                        if (this->_ds[i]->getTrangThai() == false) {
                            this->_ds[i]->capNhatNgayXuatVien(ngay);
                        }
                    }
                }
            }
        }
        freopen("CON", "rt", stdin);
    }

    // Hàm tính tổng tiền viện phí của danh sách bệnh nhân
    long tinhTongTienVienPhi() {
        long sum = 0;
        for (int i = 0; i < this->_ds.size(); i++) {
            sum += this->_ds[i]->tinhTien();
        }
        return sum;
    }
};

int main() {
    DanhSachBenhNhan danhSach;
    danhSach.nhap();

    cout << "Tong tien vien phi: " << danhSach.tinhTongTienVienPhi() << endl;

    return 0;
}
