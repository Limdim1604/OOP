#include <bits/stdc++.h>
#include "Polygon.cpp"
using namespace std;

int main() {
    int n;

    // Nhập số điểm của đa giác
    cout << "Nhap so diem cua da giac: ";
    cin >> n;

    // Kiểm tra điều kiện n > 2
    if (n <= 2) {
        cout << "So diem phai lon hon 2." << endl;
        return 1;
    }

    // Khởi tạo đối tượng Polygon và nhập tọa độ các điểm
    Polygon polygon(n);
    polygon.Nhap();

    // Tính và xuất diện tích của đa giác
    float dienTich = polygon.TinhDienTich();
    cout << "Dien tich cua da giac: " << dienTich << endl;

    return 0;
}
