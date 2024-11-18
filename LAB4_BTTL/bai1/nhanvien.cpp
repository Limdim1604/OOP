#include "NhanVien.h"
#include <bits/stdc++.h>
using namespace std;

NhanVien::NhanVien() : MaSo(""), HoTen(""), LuongCoBan(0) {}

NhanVien::NhanVien(string maSo, string hoTen, double luongCoBan)
    : MaSo(maSo), HoTen(hoTen), LuongCoBan(luongCoBan) {}

void NhanVien::Nhap() {
    cout << "Nhap ma so nhan vien: ";
    getline(cin, MaSo);
    cout << "Nhap ho ten nhan vien: ";
    getline(cin, HoTen);
    cout << "Nhap luong co ban: ";
    cin >> LuongCoBan;
    cin.ignore();
}

void NhanVien::Xuat() {
    cout << "Ma so: " << MaSo << endl;
    cout << "Ho ten: " << HoTen << endl;
    cout << "Luong co ban: " << LuongCoBan << endl;
}
