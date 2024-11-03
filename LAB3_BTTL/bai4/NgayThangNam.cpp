#include "NgayThangNam.h"
#include <iostream>

// Constructors
NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(2000) {} // Ngày mặc định là 1/1/2000

NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) {
    if (isValidDate(Ngay, Thang, Nam)) {
        iNgay = Ngay;
        iThang = Thang;
        iNam = Nam;
    } else {
        std::cerr << "Ngay khong hop le. Dat ve ngay mac dinh 1/1/2000.\n";
        iNgay = 1;
        iThang = 1;
        iNam = 2000;
    }
}

// Kiểm tra năm nhuận
bool NgayThangNam::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Lấy số ngày trong tháng
int NgayThangNam::getDaysInMonth(int month, int year) const {
    switch (month) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 31;
    }
}

// Kiểm tra tính hợp lệ của ngày tháng năm
bool NgayThangNam::isValidDate(int day, int month, int year) const {
    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;
    int daysInMonth = getDaysInMonth(month, year);
    return day <= daysInMonth;
}

// Tính tổng số ngày kể từ 1/1/0000
int NgayThangNam::TinhNgay() const {
    int totalDays = 0;
    // Tính số ngày của các năm trước đó
    for (int year = 0; year < iNam; ++year) {
        totalDays += isLeapYear(year) ? 366 : 365;
    }
    // Tính số ngày của các tháng trước đó trong năm hiện tại
    for (int month = 1; month < iThang; ++month) {
        totalDays += getDaysInMonth(month, iNam);
    }
    // Thêm số ngày trong tháng hiện tại
    totalDays += iNgay;
    return totalDays;
}

// Đặt ngày từ tổng số ngày kể từ 1/1/0000
void NgayThangNam::setDateFromTotalDays(int totalDays) {
    if (totalDays < 1) {
        std::cerr << "Tong so ngay khong hop le. Dat ve ngay mac dinh 1/1/2000.\n";
        iNgay = 1;
        iThang = 1;
        iNam = 2000;
        return;
    }
    iNam = 0;
    while (true) {
        int daysInYear = isLeapYear(iNam) ? 366 : 365;
        if (totalDays > daysInYear) {
            totalDays -= daysInYear;
            ++iNam;
        } else {
            break;
        }
    }
    iThang = 1;
    while (true) {
        int daysInMonth = getDaysInMonth(iThang, iNam);
        if (totalDays > daysInMonth) {
            totalDays -= daysInMonth;
            ++iThang;
        } else {
            break;
        }
    }
    iNgay = totalDays;
}

// Operator overloads
NgayThangNam NgayThangNam::operator+(int ngay) const {
    NgayThangNam result;
    int totalDays = this->TinhNgay() + ngay;
    result.setDateFromTotalDays(totalDays);
    return result;
}

NgayThangNam NgayThangNam::operator-(int ngay) const {
    NgayThangNam result;
    int totalDays = this->TinhNgay() - ngay;
    result.setDateFromTotalDays(totalDays);
    return result;
}

int NgayThangNam::operator-(const NgayThangNam& a) const {
    return this->TinhNgay() - a.TinhNgay();
}

// Prefix increment
NgayThangNam& NgayThangNam::operator++() {
    int totalDays = this->TinhNgay() + 1;
    this->setDateFromTotalDays(totalDays);
    return *this;
}

// Prefix decrement
NgayThangNam& NgayThangNam::operator--() {
    int totalDays = this->TinhNgay() - 1;
    this->setDateFromTotalDays(totalDays);
    return *this;
}

// Postfix increment
NgayThangNam NgayThangNam::operator++(int) {
    NgayThangNam temp = *this;
    ++(*this);
    return temp;
}

// Postfix decrement
NgayThangNam NgayThangNam::operator--(int) {
    NgayThangNam temp = *this;
    --(*this);
    return temp;
}

bool NgayThangNam::operator==(const NgayThangNam& other) const {
    return this->TinhNgay() == other.TinhNgay();
}

bool NgayThangNam::operator!=(const NgayThangNam& other) const {
    return !(*this == other);
}

bool NgayThangNam::operator>=(const NgayThangNam& other) const {
    return this->TinhNgay() >= other.TinhNgay();
}

bool NgayThangNam::operator<=(const NgayThangNam& other) const {
    return this->TinhNgay() <= other.TinhNgay();
}

bool NgayThangNam::operator>(const NgayThangNam& other) const {
    return this->TinhNgay() > other.TinhNgay();
}

bool NgayThangNam::operator<(const NgayThangNam& other) const {
    return this->TinhNgay() < other.TinhNgay();
}

// Input and output stream overloads
std::istream& operator>>(std::istream& is, NgayThangNam& date) {
    std::cout << "Nhap ngay: ";
    is >> date.iNgay;
    std::cout << "Nhap thang: ";
    is >> date.iThang;
    std::cout << "Nhap nam: ";
    is >> date.iNam;
    if (!date.isValidDate(date.iNgay, date.iThang, date.iNam)) {
        std::cerr << "Ngay thang nam khong hop le. Dat ve ngay mac dinh 1/1/2000.\n";
        date.iNgay = 1;
        date.iThang = 1;
        date.iNam = 2000;
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const NgayThangNam& date) {
    os << (date.iNgay < 10 ? "0" : "") << date.iNgay << "/"
       << (date.iThang < 10 ? "0" : "") << date.iThang << "/"
       << date.iNam;
    return os;
}
