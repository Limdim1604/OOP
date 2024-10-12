#include <bits/stdc++.h>
#include "DaGiac.cpp"
using namespace std;

int main() {
    DaGiac dg;
    double x, y;

    dg.Nhap();
    dg.Xuat();

    cout << "Nhap lan luot dx va dy de tinh tien: ";
    cin >> x >> y;
    dg.TinhTien(x, y);
    cout << "\nToa do da giac sau khi tinh tien: " << endl;
    dg.Xuat();

    cout << "Nhap he so muon phong to da giac: ";
    cin >> x;
    dg.PhongTo(x);
    cout << "\nDa giac sau khi duoc phong to voi he so la: " << endl;
    dg.Xuat();

    cout << "Nhap he so muon thu nho da giac: ";
    cin >> x;
    dg.ThuNho(x);
    cout << "\nDa giac sau khi thu nho voi he so la: " << endl;
    dg.Xuat();

    cout << "Nhap goc de quay da giac (theo do): ";
    cin >> x;
    dg.Quay(x * (M_PI / 180.0));
    cout << "\nDa giac sau khi quay la: " << endl;
    dg.Xuat();

    return 0;
}
