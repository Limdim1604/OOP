#ifndef KYSU_H
#define KYSU_H

#include "NhanVien.h"

class KySu : public NhanVien {
private:
    int SoGioLamThem;
public:
    KySu();
    KySu(string maSo, string hoTen, double luongCoBan, int soGioLamThem);
    void Nhap();
    void Xuat();
    double TienThuong();
};

#endif
