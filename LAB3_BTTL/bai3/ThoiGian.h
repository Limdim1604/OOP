#pragma once
#include <iostream>

class ThoiGian {
private:
    int iGio;   // Giờ
    int iPhut;  // Phút
    int iGiay;  // Giây

public:
    // Constructors
    ThoiGian(); // Khởi tạo thời gian mặc định là 0:0:0
    ThoiGian(int Gio, int Phut, int Giay); // Khởi tạo thời gian với giờ, phút, giây

    // Tính tổng số giây của thời gian hiện tại
    int TinhGiay() const;
    // Chuyển từ giây về lại giờ, phút, giây
    void TinhLaiGio(int Giay);

    // Operator overloads
    ThoiGian operator+(int Giay) const; // Thêm giây vào thời gian
    ThoiGian operator-(int Giay) const; // Trừ giây khỏi thời gian
    ThoiGian operator+(const ThoiGian& a) const; // Cộng hai thời gian
    ThoiGian operator-(const ThoiGian& a) const; // Trừ hai thời gian

    // Prefix increment and decrement operators
    ThoiGian& operator++();   // Tiền tố ++
    ThoiGian& operator--();   // Tiền tố --

    // Postfix increment and decrement operators
    ThoiGian operator++(int); // Hậu tố ++
    ThoiGian operator--(int); // Hậu tố --

    bool operator==(const ThoiGian& other) const;
    bool operator!=(const ThoiGian& other) const;
    bool operator>=(const ThoiGian& other) const;
    bool operator<=(const ThoiGian& other) const;
    bool operator>(const ThoiGian& other) const;
    bool operator<(const ThoiGian& other) const;

    // Input and output stream overloads
    friend std::istream& operator>>(std::istream& is, ThoiGian& tg);
    friend std::ostream& operator<<(std::ostream& os, const ThoiGian& tg);
};
