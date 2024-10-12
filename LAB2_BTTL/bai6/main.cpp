#include <bits/stdc++.h>
#include "TamGiac.cpp"
using namespace std;

int main() {
    float x1, y1, x2, y2, x3, y3;
    float goc, doDai;

    // Nhập tọa độ 3 điểm của tam giác
    cout << "Nhap toa do 3 diem cua tam giac (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Khởi tạo đối tượng TamGiac
    TamGiac tamGiac(x1, y1, x2, y2, x3, y3);

    // Nhập góc và độ dài tịnh tiến
    cout << "Nhap goc tịnh tien (do) va do dai tinh tien: ";
    cin >> goc >> doDai;

    // Tịnh tiến tam giác
    tamGiac.TinhTien(goc, doDai);

    // Xuất tọa độ tam giác sau khi tịnh tiến
    cout << "Toa do tam giac sau khi tinh tien:" << endl;
    tamGiac.Xuat();

    return 0;
}
