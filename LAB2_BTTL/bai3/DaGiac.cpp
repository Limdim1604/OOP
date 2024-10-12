#include <bits/stdc++.h>
#include "DaGiac.h"
using namespace std;

DaGiac::DaGiac() : n(0), Dinh(nullptr) {}

DaGiac::DaGiac(int soDinh) : n(soDinh) {
    Dinh = new Diem[n];
}

DaGiac::~DaGiac() {
    delete[] Dinh;
}

void DaGiac::Nhap() {
    cout << "Nhap so dinh cua da giac: ";
    cin >> n;
    Dinh = new Diem[n];
    for (int i = 0; i < n; i++) {
        double x, y;
        cout << "Nhap toa do dinh " << i + 1 << ": ";
        cin >> x >> y;
        Dinh[i] = Diem(x, y);
    }
}

void DaGiac::Xuat() const {
    cout << "Toa do cac dinh cua da giac: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Dinh " << i + 1 << ": ";
        Dinh[i].Xuat();
    }
}

void DaGiac::TinhTien(double dx, double dy) {
    for (int i = 0; i < n; i++) {
        Dinh[i].TinhTien(dx, dy);
    }
}

void DaGiac::PhongTo(double scale) {
    for (int i = 0; i < n; i++) {
        Dinh[i].SetHoanhDo(Dinh[i].GetHoanhDo() * scale);
        Dinh[i].SetTungDo(Dinh[i].GetTungDo() * scale);
    }
}

void DaGiac::ThuNho(double scale) {
    if (scale != 0) {
        PhongTo(1.0 / scale);
    }
}

void DaGiac::Quay(double rad) {
    for (int i = 0; i < n; i++) {
        Dinh[i].Quay(rad);
    }
}
