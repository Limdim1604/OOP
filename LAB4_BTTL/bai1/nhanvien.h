#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <bits/stdc++.h>
using namespace std;

class NhanVien {
protected:
    string MaSo;
    string HoTen;
    double LuongCoBan;
public:
    NhanVien();
    NhanVien(string maSo, string hoTen, double luongCoBan);
    virtual void Nhap();
    virtual void Xuat();
    virtual double TienThuong() = 0; // Phương thức thuần ảo
};

#endif
