#include "Deluxe.h"
#include <iostream>
using namespace std;

Deluxe::Deluxe() : Room(), PhiDichVu(0), PhiPhucVu(0) {}

Deluxe::Deluxe(int soDem, double phiDichVu, double phiPhucVu)
    : Room(soDem), PhiDichVu(phiDichVu), PhiPhucVu(phiPhucVu) {}

void Deluxe::Nhap() {
    Room::Nhap();
    cout << "Nhap phi dich vu: ";
    cin >> PhiDichVu;
    cout << "Nhap phi phuc vu: ";
    cin >> PhiPhucVu;
}

double Deluxe::TinhDoanhThu() {
    return SoDem * 750000 + PhiDichVu + PhiPhucVu;
}
