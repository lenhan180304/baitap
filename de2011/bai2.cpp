#include <iostream>
using namespace std;

class MayXucTac {
private:
    static long DON_GIA_THUE_XUC_TAC;  // Đơn giá thuê máy xúc tác
    static long DON_GIA_HOA_CHAT;      // Đơn giá hóa chất
    float congSuatLoc;                 // Công suất lọc của máy
    float thoiGianHoatDong;            // Thời gian hoạt động của máy (giờ)
    float luongHoaChat;                 // Lượng hóa chất sử dụng (gram)

public:
    // Constructor mặc định với giá trị mặc định cho các thuộc tính
    MayXucTac() : congSuatLoc(0), thoiGianHoatDong(0), luongHoaChat(0) {}

    // Phương thức để nhập thông tin sử dụng của máy xúc tác
    void nhap() {
        cout << "Nhap cong suat loc (m3/h): ";
        cin >> congSuatLoc;
        cout << "Nhap thoi gian hoat dong (h): ";
        cin >> thoiGianHoatDong;
        cout << "Nhap luong hoa chat (g): ";
        cin >> luongHoaChat;
    }

    // Phương thức tính lượng nước được lọc bởi máy xúc tác
    float tinhLuongNuoc() const {
        // Công suất lọc thực tế được tính dựa trên thời gian hoạt động và lượng hóa chất
        float congSuatThucTe = (thoiGianHoatDong < 10) ?
                               (congSuatLoc * (luongHoaChat / 100)) :
                               (congSuatLoc * (luongHoaChat / 100) / (thoiGianHoatDong / 10));

        // Lượng nước được lọc là công suất lọc thực tế nhân với thời gian hoạt động
        return congSuatThucTe * thoiGianHoatDong;
    }

    // Phương thức tính chi phí sử dụng máy xúc tác
    long tinhChiPhi() const {
        // Chi phí thuê máy là đơn giá thuê nhân với thời gian hoạt động
        long chiPhiThue = DON_GIA_THUE_XUC_TAC * thoiGianHoatDong;

        // Chi phí sử dụng máy là chi phí thuê cộng với chi phí hóa chất
        long chiPhiHoaChat = luongHoaChat * DON_GIA_HOA_CHAT;
        return chiPhiThue + chiPhiHoaChat;
    }

    // Phương thức public để lấy giá trị đơn giá hóa chất
    static long layDonGiaHoaChat() {
        return DON_GIA_HOA_CHAT;
    }
};

// Khởi tạo giá trị cho các thuộc tính static
long MayXucTac::DON_GIA_THUE_XUC_TAC = 80000;
long MayXucTac::DON_GIA_HOA_CHAT = 10000;

int main() {
    // Hiển thị đơn giá hóa chất
    cout << "Don gia hoa chat: " << MayXucTac::layDonGiaHoaChat() << endl;

    // Tạo một đối tượng máy xúc tác và nhập thông tin sử dụng
    MayXucTac m;
    m.nhap();

    // Hiển thị chi phí sử dụng máy và lượng nước lọc được
    cout << "Chi phi su dung may: " << m.tinhChiPhi() << endl;
    cout << "Luong nuoc loc duoc: " << m.tinhLuongNuoc() << endl;

    return 0;
}
