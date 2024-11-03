#include "ThoiGian.h"
#include <iostream>

// Constructors
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {} // Thời gian mặc định là 0:0:0

ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {}

// Tính tổng số giây của thời gian hiện tại
int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

// Chuyển số giây thành giờ, phút, giây
void ThoiGian::TinhLaiGio(int Giay) {
    if (Giay < 0) Giay = 0;
    iGio = Giay / 3600;
    Giay %= 3600;
    iPhut = Giay / 60;
    iGiay = Giay % 60;
}

// Operator overloads
ThoiGian ThoiGian::operator+(int Giay) const {
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() + Giay);
    return result;
}

ThoiGian ThoiGian::operator-(int Giay) const {
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() - Giay);
    return result;
}

ThoiGian ThoiGian::operator+(const ThoiGian& a) const {
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() + a.TinhGiay());
    return result;
}

ThoiGian ThoiGian::operator-(const ThoiGian& a) const {
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() - a.TinhGiay());
    return result;
}

// Prefix increment
ThoiGian& ThoiGian::operator++() {
    int totalSeconds = this->TinhGiay() + 1;
    this->TinhLaiGio(totalSeconds);
    return *this;
}

// Prefix decrement
ThoiGian& ThoiGian::operator--() {
    int totalSeconds = this->TinhGiay() - 1;
    this->TinhLaiGio(totalSeconds);
    return *this;
}

// Postfix increment
ThoiGian ThoiGian::operator++(int) {
    ThoiGian temp = *this;
    ++(*this);
    return temp;
}

// Postfix decrement
ThoiGian ThoiGian::operator--(int) {
    ThoiGian temp = *this;
    --(*this);
    return temp;
}

bool ThoiGian::operator==(const ThoiGian& other) const {
    return this->TinhGiay() == other.TinhGiay();
}

bool ThoiGian::operator!=(const ThoiGian& other) const {
    return !(*this == other);
}

bool ThoiGian::operator>=(const ThoiGian& other) const {
    return this->TinhGiay() >= other.TinhGiay();
}

bool ThoiGian::operator<=(const ThoiGian& other) const {
    return this->TinhGiay() <= other.TinhGiay();
}

bool ThoiGian::operator>(const ThoiGian& other) const {
    return this->TinhGiay() > other.TinhGiay();
}

bool ThoiGian::operator<(const ThoiGian& other) const {
    return this->TinhGiay() < other.TinhGiay();
}

// Input and output stream overloads
std::istream& operator>>(std::istream& is, ThoiGian& tg) {
    std::cout << "Nhap gio: ";
    is >> tg.iGio;
    std::cout << "Nhap phut: ";
    is >> tg.iPhut;
    std::cout << "Nhap giay: ";
    is >> tg.iGiay;
    return is;
}

std::ostream& operator<<(std::ostream& os, const ThoiGian& tg) {
    os << (tg.iGio < 10 ? "0" : "") << tg.iGio << ":"
       << (tg.iPhut < 10 ? "0" : "") << tg.iPhut << ":"
       << (tg.iGiay < 10 ? "0" : "") << tg.iGiay;
    return os;
}
