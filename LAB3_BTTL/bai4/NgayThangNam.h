#pragma once
#include <iostream>

class NgayThangNam {
private:
    int iNgay;   // Ngày
    int iThang;  // Tháng
    int iNam;    // Năm

    // Kiểm tra năm nhuận
    bool isLeapYear(int year) const;
    // Lấy số ngày trong tháng
    int getDaysInMonth(int month, int year) const;
    // Kiểm tra tính hợp lệ của ngày tháng năm
    bool isValidDate(int day, int month, int year) const;

public:
    // Constructors
    NgayThangNam(); // Khởi tạo ngày mặc định là 1/1/2000
    NgayThangNam(int Nam, int Thang, int Ngay); // Khởi tạo với ngày, tháng, năm

    // Tính tổng số ngày kể từ 1/1/0000
    int TinhNgay() const;
    // Đặt ngày từ tổng số ngày
    void setDateFromTotalDays(int totalDays);

    // Operator overloads
    NgayThangNam operator+(int ngay) const;            // Thêm số ngày
    NgayThangNam operator-(int ngay) const;            // Trừ số ngày
    int operator-(const NgayThangNam& a) const;        // Hiệu giữa hai ngày (số ngày)
    
    // Prefix increment and decrement operators
    NgayThangNam& operator++();   // Tiền tố ++
    NgayThangNam& operator--();   // Tiền tố --
    
    // Postfix increment and decrement operators
    NgayThangNam operator++(int); // Hậu tố ++
    NgayThangNam operator--(int); // Hậu tố --

    bool operator==(const NgayThangNam& other) const;
    bool operator!=(const NgayThangNam& other) const;
    bool operator>=(const NgayThangNam& other) const;
    bool operator<=(const NgayThangNam& other) const;
    bool operator>(const NgayThangNam& other) const;
    bool operator<(const NgayThangNam& other) const;

    // Input and output stream overloads
    friend std::istream& operator>>(std::istream& is, NgayThangNam& date);
    friend std::ostream& operator<<(std::ostream& os, const NgayThangNam& date);
};
