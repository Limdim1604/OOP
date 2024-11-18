#include "QuanLy.h"
#include <bits/stdc++.h>
using namespace std;

QuanLy::QuanLy() : NhanVien(), TyLeThuong(0) {}

QuanLy::QuanLy(string maSo, string hoTen, double luongCoBan, double tyLeThuong)
    : NhanVien(maSo, hoTen, luongCoBan), TyLeThuong(tyLeThuong) {}

void QuanLy::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap ty le thuong (vi du: 0.1 cho 10%): ";
    cin >> TyLeThuong;
    cin.ignore();
}

void QuanLy::Xuat() {
    NhanVien::Xuat();
    cout << "Ty le thuong: " << TyLeThuong << endl;
    cout << "Tien thuong: " << TienThuong() << endl;
}

double QuanLy::TienThuong() {
    return LuongCoBan * TyLeThuong;
}
