#include "Premium.h"
#include <bits/stdc++.h>
using namespace std;

Premium::Premium() : Room(), PhiDichVu(0) {}

Premium::Premium(int soDem, double phiDichVu)
    : Room(soDem), PhiDichVu(phiDichVu) {}

void Premium::Nhap() {
    Room::Nhap();
    cout << "Nhap phi dich vu: ";
    cin >> PhiDichVu;
}

double Premium::TinhDoanhThu() {
    return SoDem * 500000 + PhiDichVu;
}
