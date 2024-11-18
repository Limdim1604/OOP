#include "KySu.h"
#include <bits/stdc++.h>
using namespace std;

KySu::KySu() : NhanVien(), SoGioLamThem(0) {}

KySu::KySu(string maSo, string hoTen, double luongCoBan, int soGioLamThem)
    : NhanVien(maSo, hoTen, luongCoBan), SoGioLamThem(soGioLamThem) {}

void KySu::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap so gio lam them: ";
    cin >> SoGioLamThem;
    cin.ignore();
}

void KySu::Xuat() {
    NhanVien::Xuat();
    cout << "So gio lam them: " << SoGioLamThem << endl;
    cout << "Tien thuong: " << TienThuong() << endl;
}

double KySu::TienThuong() {
    return SoGioLamThem * 100000;
}
