#include <bits/stdc++.h>
#include "Diem.h"
using namespace std;

// Khởi tạo điểm với tọa độ (0, 0) mặc định
Diem::Diem() : Hoanh(0), Tung(0) {}

// Khởi tạo điểm với giá trị hoành độ và tung độ được chỉ định
Diem::Diem(float hoanh, float tung) : Hoanh(hoanh), Tung(tung) {}

// In ra tọa độ của điểm
void Diem::Xuat() const {
    cout << "(" << Hoanh << ", " << Tung << ")" << endl;
}

// Chỉ thị 1: Nhân đôi hoành độ và tung độ của điểm
void Diem::NhanDoi() {
    Hoanh *= 2;
    Tung *= 2;
}

// Chỉ thị 2: Gán hoành độ và tung độ về gốc tọa độ (0, 0)
void Diem::GanGocToaDo() {
    Hoanh = 0;
    Tung = 0;
}

// Chỉ thị 3: Tịnh tiến điểm theo hướng k và độ tịnh tiến d
// - Nếu k = 0: tịnh tiến theo trục x (hoành độ)
// - Nếu k khác 0: tịnh tiến theo trục y (tung độ)
void Diem::TinhTien(int k, float d) {
    if (k == 0) {
        Hoanh += d;  // Tịnh tiến theo trục x
    } else {
        Tung += d;   // Tịnh tiến theo trục y
    }
}
