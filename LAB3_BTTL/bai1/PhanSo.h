#pragma once
#include <iostream>

class PhanSo {
private:
    int iTu; // Tử số 
    int iMau; // Mẫu số 

public:
    // Constructors
    PhanSo(); // Khởi tạo phân số mặc định
    PhanSo(int Tu, int Mau); // Khởi tạo phân số với tử và mẫu

    // Operator overloads :v
    PhanSo operator+(const PhanSo& other) const;
    PhanSo operator-(const PhanSo& other) const;
    PhanSo operator*(const PhanSo& other) const;
    PhanSo operator/(const PhanSo& other) const;

    bool operator==(const PhanSo& other) const;
    bool operator!=(const PhanSo& other) const;
    bool operator>=(const PhanSo& other) const;
    bool operator<=(const PhanSo& other) const;
    bool operator>(const PhanSo& other) const;
    bool operator<(const PhanSo& other) const;

    // Input và output stream overloads
    friend std::istream& operator>>(std::istream& is, PhanSo& ps);
    friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps);

private:
    void simplify(); // Hàm rút gọn phân số
    int gcd(int a, int b) const; // Hàm tính ước chung lớn nhất
};
