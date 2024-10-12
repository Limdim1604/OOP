#include <bits/stdc++.h>
#include "ThiSinh.h"
using namespace std;

ThiSinh::ThiSinh() : iNgay(0), iThang(0), iNam(0), fToan(0), fVan(0), fAnh(0) {}

void ThiSinh::Nhap() {
    cout << "Nhap ten: ";
    getline(cin >> ws, Ten);
    cout << "Nhap MSSV: ";
    getline(cin, MSSV);
    cout << "Nhap ngay sinh (dd mm yyyy): ";
    cin >> iNgay >> iThang >> iNam;
    cout << "Nhap diem Toan: ";
    cin >> fToan;
    cout << "Nhap diem Van: ";
    cin >> fVan;
    cout << "Nhap diem Anh: ";
    cin >> fAnh;
}

void ThiSinh::Xuat() const {
    cout << "Ten: " << Ten << endl;
    cout << "MSSV: " << MSSV << endl;
    cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << endl;
    cout << "Diem Toan: " << fToan << ", Diem Van: " << fVan << ", Diem Anh: " << fAnh << endl;
    cout << "Tong diem: " << Tong() << endl;
}

float ThiSinh::Tong() const {
    return fToan + fVan + fAnh;
}

string ThiSinh::getMSSV() const {
    return MSSV;
}
