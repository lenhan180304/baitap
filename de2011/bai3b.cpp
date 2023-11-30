#include <iostream>
#include <vector>

using namespace std;

// Lớp cơ sở cho máy lọc
class MayLoc {
protected:
    long donGiaThue;
public:
    virtual void nhap() = 0; // Hàm ảo để nhập thông tin máy lọc
    virtual float tinhCongSuatLoc() const = 0; // Hàm ảo để tính công suất lọc
    virtual long tinhChiPhi() const = 0; // Hàm ảo để tính chi phí máy lọc
};

// Lớp con cho máy ly tâm
class MayLyTam : public MayLoc {
public:
    void nhap() override {
        cout << "Nhap don gia thue may ly tam (dong/h): ";
        cin >> donGiaThue;
    }

    float tinhCongSuatLoc() const override {
        return 1.0; // Giả sử công suất lọc không đổi cho máy ly tâm
    }

    long tinhChiPhi() const override {
        long luongXang;
        cout << "Nhap luong xang tieu thu (lit): ";
        cin >> luongXang;
        return luongXang * 20000; // Chi phí nhiên liệu
    }
};

// Lớp con cho máy xúc tác
class MayXucTac : public MayLoc {
private:
    float luongHoaChat;
    int thoiGianSuDung;
public:
    void nhap() override {
        cout << "Nhap don gia thue may xuc tac (dong/h): ";
        cin >> donGiaThue;
        cout << "Nhap luong hoa chat (kg): ";
        cin >> luongHoaChat;
        cout << "Nhap thoi gian su dung (gio): ";
        cin >> thoiGianSuDung;
    }

    float tinhCongSuatLoc() const override {
        // Giả sử công suất lọc thay đổi theo thời gian sử dụng và lượng hóa chất
        return thoiGianSuDung * luongHoaChat;
    }

    long tinhChiPhi() const override {
        return luongHoaChat * 10000; // Chi phí hóa chất
    }
};

// Lớp quản lý danh sách máy lọc
class DanhSachMayLoc {
private:
    vector<MayLoc*> danhSachMayLoc;
public:
    void nhapDanhSachMayLoc() {
        int soLuongMayLoc;
        cout << "Nhap so luong may loc: ";
        cin >> soLuongMayLoc;

        danhSachMayLoc.resize(soLuongMayLoc);

        for (int i = 0; i < soLuongMayLoc; i++) {
            int loaiMayLoc;
            cout << "Nhap loai may loc (1: May ly tam, 2: May xuc tac): ";
            cin >> loaiMayLoc;

            if (loaiMayLoc == 1) {
                danhSachMayLoc[i] = new MayLyTam();
            } else if (loaiMayLoc == 2) {
                danhSachMayLoc[i] = new MayXucTac();
            } else {
                cout << "Loai may loc khong hop le.\n";
                i--; // Yêu cầu nhập lại loại máy lọc
            }

            danhSachMayLoc[i]->nhap();
        }
    }

    float tinhTongCongSuatLoc() const {
        float tongCongSuat = 0.0;
        for (const auto& mayLoc : danhSachMayLoc) {
            tongCongSuat += mayLoc->tinhCongSuatLoc();
        }
        return tongCongSuat;
    }

    long tinhTongChiPhi() const {
        long tongChiPhi = 0;
        for (const auto& mayLoc : danhSachMayLoc) {
            tongChiPhi += mayLoc->tinhChiPhi();
        }
        return tongChiPhi;
    }

    ~DanhSachMayLoc() {
        for (const auto& mayLoc : danhSachMayLoc) {
            delete mayLoc;
        }
    }
};

// Lớp quản lý ao nuoi
class Ao {
private:
    float luongNuoc;
    DanhSachMayLoc danhSachMayLoc;
public:
    void nhapThongTinAo() {
        cout << "Nhap luong nuoc trong ao (m3): ";
        cin >> luongNuoc;

        danhSachMayLoc.nhapDanhSachMayLoc();
    }

    void hienThiKetQua() const {
        cout << "Tong cong suat loc: " << danhSachMayLoc.tinhTongCongSuatLoc() << endl;

        if (luongNuoc <= danhSachMayLoc.tinhTongCongSuatLoc()) {
            cout << "Ao duoc loc het nuoc.\n";
        } else {
            cout << "Ao khong duoc loc het nuoc.\n";
        }

        cout << "Tong chi phi su dung may loc: " << danhSachMayLoc.tinhTongChiPhi() << " dong.\n";
    }
};

int main() {
    Ao ao;
    ao.nhapThongTinAo();
    ao.hienThiKetQua();

    return 0;
}
