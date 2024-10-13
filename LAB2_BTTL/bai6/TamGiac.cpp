#include <bits/stdc++.h>
#include "TamGiac.h"
using namespace std;

TamGiac::TamGiac(float x1, float y1, float x2, float y2, float x3, float y3)
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

// Tịnh tiến tam giác theo góc và độ dài
void TamGiac::TinhTien(float goc, float doDai) {
    // Chuyển đổi góc từ độ sang radian
    float rad = goc * M_PI / 180.0;

    // Tính thành phần tịnh tiến trên trục x và y
    float dx = doDai * cos(rad);
    float dy = doDai * sin(rad);

    // Tịnh tiến mỗi điểm
    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
    x3 += dx;
    y3 += dy;
}

// In ra tọa độ của tam giác
void TamGiac::Xuat() const {
    cout << "(" << x1 << "," << y1 << ")" << endl;
    cout << "(" << x2 << "," << y2 << ")" << endl;
    cout << "(" << x3 << "," << y3 << ")" << endl;
}
