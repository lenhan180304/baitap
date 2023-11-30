// Phương thức khởi tạo mặc định của lớp Bike
Bike() {
    // Khởi tạo brand là chuỗi "Bike"
    char s[5] = "Bike";
    this->brand = new char[5];
    for (int i = 0; i < 5; i++) {
        this->brand[i] = s[i];
    }
}

// Phương thức khởi tạo của lớp Bike với tham số là chuỗi s
Bike(char s[]) {
    // Cấp phát bộ nhớ cho brand với kích thước là độ dài của chuỗi s + 1
    this->brand = new char[strlen(s) + 1];
    for (int i = 0; i < strlen(s); i++) {
        this->brand[i] = s[i];
    }
    this->brand[strlen(s)] = '\0';  // Đặt ký tự kết thúc chuỗi
}

// Phương thức hủy của lớp Bike
~Bike() {
    if (this->brand) {
        delete[] this->brand;  // Giải phóng bộ nhớ brand nếu nó đã được cấp phát
    }
}

// Phương thức khởi tạo của lớp EBike với tham số là chuỗi s
EBike(char s[]) : Bike("EBike") {}  // Gọi phương thức khởi tạo của lớp cơ sở Bike
