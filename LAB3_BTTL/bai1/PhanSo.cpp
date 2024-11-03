#include "PhanSo.h"
#include <iostream>

// Constructors
PhanSo::PhanSo() : iTu(0), iMau(1) {} // Phân số mặc định là 0/1

PhanSo::PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) {
    simplify(); // Rút gọn phân số ngay khi khởi tạo
}

// Operator overloads
PhanSo PhanSo::operator+(const PhanSo& other) const {
    return PhanSo(iTu * other.iMau + other.iTu * iMau, iMau * other.iMau);
}

PhanSo PhanSo::operator-(const PhanSo& other) const {
    return PhanSo(iTu * other.iMau - other.iTu * iMau, iMau * other.iMau);
}

PhanSo PhanSo::operator*(const PhanSo& other) const {
    return PhanSo(iTu * other.iTu, iMau * other.iMau);
}

PhanSo PhanSo::operator/(const PhanSo& other) const {
    return PhanSo(iTu * other.iMau, iMau * other.iTu);
}

bool PhanSo::operator==(const PhanSo& other) const {
    return iTu * other.iMau == iMau * other.iTu;
}

bool PhanSo::operator!=(const PhanSo& other) const {
    return !(*this == other);
}

bool PhanSo::operator>=(const PhanSo& other) const {
    return iTu * other.iMau >= iMau * other.iTu;
}

bool PhanSo::operator<=(const PhanSo& other) const {
    return iTu * other.iMau <= iMau * other.iTu;
}

bool PhanSo::operator>(const PhanSo& other) const {
    return iTu * other.iMau > iMau * other.iTu;
}

bool PhanSo::operator<(const PhanSo& other) const {
    return iTu * other.iMau < iMau * other.iTu;
}

// Input và output stream overloads
std::istream& operator>>(std::istream& is, PhanSo& ps) {
    std::cout << "Nhap tu so: ";
    is >> ps.iTu;
    std::cout << "Nhap mau so: ";
    is >> ps.iMau;
    ps.simplify(); // Rút gọn phân số sau khi nhập
    return is;
}

std::ostream& operator<<(std::ostream& os, const PhanSo& ps) {
    os << ps.iTu << "/" << ps.iMau;
    return os;
}

// Private methods
void PhanSo::simplify() {
    int divisor = gcd(iTu, iMau);
    iTu /= divisor;
    iMau /= divisor;
    if (iMau < 0) { // đổi lại cho đẹp nếu mẫu số âm
        iTu = -iTu;
        iMau = -iMau;
    }
}

int PhanSo::gcd(int a, int b) const {
    return b == 0 ? a : gcd(b, a % b);
}
