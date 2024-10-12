#include <bits/stdc++.h>
#include "Polygon.h"
using namespace std;

// Khởi tạo đa giác với số điểm n
Polygon::Polygon(int soDinh) : n(soDinh) {
    Dinh.resize(n);
}

// Nhập tọa độ của các điểm trong đa giác
void Polygon::Nhap() {
    cout << "Nhap toa do cac diem cua da giac:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Dinh " << i + 1 << ": ";
        cin >> Dinh[i].first >> Dinh[i].second;
    }
}

// Tính diện tích của đa giác bằng công thức Shoelace
float Polygon::TinhDienTich() const {
    float dienTich = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n; // Điểm tiếp theo, vòng lại từ đầu khi hết
        dienTich += Dinh[i].first * Dinh[j].second - Dinh[j].first * Dinh[i].second;
    }
    return abs(dienTich) / 2.0;
}
