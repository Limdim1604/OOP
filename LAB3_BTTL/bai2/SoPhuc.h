#pragma once
#include <iostream>

class SoPhuc {
private:
    double dThuc; // Phần thực của số phức
    double dAo; // Phần ảo của số phức

public:
    // Constructors
    SoPhuc(); // Khởi tạo số phức mặc định
    SoPhuc(double thuc, double ao); // Khởi tạo số phức với phần thực và phần ảo

    // Operator overloads
    SoPhuc operator+(const SoPhuc& other) const; // Cộng hai số phức
    SoPhuc operator-(const SoPhuc& other) const; // Trừ hai số phức
    SoPhuc operator*(const SoPhuc& other) const; // Nhân hai số phức
    SoPhuc operator/(const SoPhuc& other) const; // Chia hai số phức

    bool operator==(const SoPhuc& other) const; // So sánh hai số phức bằng nhau
    bool operator!=(const SoPhuc& other) const; // So sánh hai số phức khác nhau

    // Input and output stream overloads
    friend std::istream& operator>>(std::istream& is, SoPhuc& sp); // Nhập số phức
    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& sp); // Xuất số phức
};
