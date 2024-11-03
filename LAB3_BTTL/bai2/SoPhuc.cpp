#include "SoPhuc.h"
#include <iostream>

// Constructors
SoPhuc::SoPhuc() : dThuc(0), dAo(0) {} // Số phức mặc định là 0 + 0i

SoPhuc::SoPhuc(double thuc, double ao) : dThuc(thuc), dAo(ao) {} // Khởi tạo với phần thực và phần ảo

// Operator overloads
SoPhuc SoPhuc::operator+(const SoPhuc& other) const {
    // Cộng phần thực và phần ảo của hai số phức
    return SoPhuc(dThuc + other.dThuc, dAo + other.dAo);
}

SoPhuc SoPhuc::operator-(const SoPhuc& other) const {
    // Trừ phần thực và phần ảo của hai số phức
    return SoPhuc(dThuc - other.dThuc, dAo - other.dAo);
}

SoPhuc SoPhuc::operator*(const SoPhuc& other) const {
    // Nhân hai số phức theo công thức (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    return SoPhuc(dThuc * other.dThuc - dAo * other.dAo, dThuc * other.dAo + dAo * other.dThuc);
}

SoPhuc SoPhuc::operator/(const SoPhuc& other) const {
    // Chia hai số phức theo công thức (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c^2 + d^2)
    double denominator = other.dThuc * other.dThuc + other.dAo * other.dAo; // Mẫu số
    return SoPhuc((dThuc * other.dThuc + dAo * other.dAo) / denominator, 
                  (dAo * other.dThuc - dThuc * other.dAo) / denominator);
}

bool SoPhuc::operator==(const SoPhuc& other) const {
    // Kiểm tra hai số phức bằng nhau khi phần thực và phần ảo đều bằng nhau
    return dThuc == other.dThuc && dAo == other.dAo;
}

bool SoPhuc::operator!=(const SoPhuc& other) const {
    // Kiểm tra hai số phức khác nhau
    return !(*this == other);
}

// Input and output stream overloads
std::istream& operator>>(std::istream& is, SoPhuc& sp) {
    // Nhập phần thực và phần ảo từ người dùng
    std::cout << "Nhap phan thuc: ";
    is >> sp.dThuc;
    std::cout << "Nhap phan ao: ";
    is >> sp.dAo;
    return is;
}

std::ostream& operator<<(std::ostream& os, const SoPhuc& sp) {
    // Kiểm tra và chỉ hiển thị các phần thực và ảo nếu khác 0
    if (sp.dThuc != 0) os << sp.dThuc; // Hiển thị phần thực nếu khác 0
    if (sp.dAo != 0) {
        if (sp.dThuc != 0) os << (sp.dAo > 0 ? " + " : " - ");
        os << std::abs(sp.dAo) << "i"; // Hiển thị phần ảo, dùng "i" để biểu thị số phức
    }
    if (sp.dThuc == 0 && sp.dAo == 0) os << "0"; // Hiển thị "0" nếu cả hai đều bằng 0
    return os;
}
