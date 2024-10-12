#include <bits/stdc++.h>
#include "Diem.h"
using namespace std;

Diem::Diem() : Hoanh(0), Tung(0) {}

Diem::Diem(double Hoanh, double Tung) : Hoanh(Hoanh), Tung(Tung) {}

Diem::Diem(const Diem &x) : Hoanh(x.Hoanh), Tung(x.Tung) {}

void Diem::Xuat() {
    cout << "(" << Hoanh << ", " << Tung << ")" << endl;
}

double Diem::GetTungDo() {
    return Tung;
}

double Diem::GetHoanhDo() {
    return Hoanh;
}

void Diem::SetTungDo(double Tung) {
    this->Tung = Tung;
}

void Diem::SetHoanhDo(double Hoanh) {
    this->Hoanh = Hoanh;
}

void Diem::TinhTien(double dx, double dy) {
    Hoanh += dx;
    Tung += dy;
}

void Diem::Quay(double rad) {
    double x_old = Hoanh;
    double y_old = Tung;
    Hoanh = x_old * cos(rad) - y_old * sin(rad);
    Tung = x_old * sin(rad) + y_old * cos(rad);
}
