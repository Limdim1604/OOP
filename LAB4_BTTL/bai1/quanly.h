#ifndef QUANLY_H
#define QUANLY_H

#include "NhanVien.h"

class QuanLy : public NhanVien {
private:
    double TyLeThuong;
public:
    QuanLy();
    QuanLy(string maSo, string hoTen, double luongCoBan, double tyLeThuong);
    void Nhap();
    void Xuat();
    double TienThuong();
};

#endif
