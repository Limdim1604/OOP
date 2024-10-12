#include <bits/stdc++.h>
#include "TamGiac.h"
using namespace std;

void TamGiac::Nhap() {
    double x, y;
    cout << "Nhap toa do x va y cua diem A: ";
    cin >> x >> y;
    A = Diem(x, y);

    cout << "Nhap toa do x va y cua diem B: ";
    cin >> x >> y;
    B = Diem(x, y);

    cout << "Nhap toa do x va y cua diem C: ";
    cin >> x >> y;
    C = Diem(x, y);
}

void TamGiac::Xuat() {
    cout << "Toa do tam giac la: " << endl;
    cout << "A: ";
    A.Xuat();
    cout << "B: ";
    B.Xuat();
    cout << "C: ";
    C.Xuat();
}

void TamGiac::TinhTien(double dx, double dy) {
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

void TamGiac::PhongTo(double k) {
    A.SetHoanhDo(A.GetHoanhDo() * k);
    A.SetTungDo(A.GetTungDo() * k);
    B.SetHoanhDo(B.GetHoanhDo() * k);
    B.SetTungDo(B.GetTungDo() * k);
    C.SetHoanhDo(C.GetHoanhDo() * k);
    C.SetTungDo(C.GetTungDo() * k);
}

void TamGiac::ThuNho(double k) {
    if (k != 0) {
        PhongTo(1.0 / k);
    }
}

void TamGiac::Quay(double radian) {
    A.Quay(radian);
    B.Quay(radian);
    C.Quay(radian);
}
