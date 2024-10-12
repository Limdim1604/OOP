#include <bits/stdc++.h>
#include "TamGiac.cpp"
using namespace std;

int main() {
    TamGiac tg;
    double x, y;

    tg.Nhap();
    tg.Xuat();

    cout << "Nhap lan luot dx va dy de tinh tien: ";
    cin >> x >> y;
    tg.TinhTien(x, y);
    cout << "\nToa do tam giac sau khi tinh tien: " << endl;
    tg.Xuat();

    cout << "Nhap he so muon phong to tam giac: ";
    cin >> x;
    tg.PhongTo(x);
    cout << "\nTam giac sau khi duoc phong to voi he so la: " << endl;
    tg.Xuat();

    cout << "Nhap he so muon thu nho tam giac: ";
    cin >> x;
    tg.ThuNho(x);
    cout << "\nTam giac sau khi thu nho voi he so la: " << endl;
    tg.Xuat();

    cout << "Nhap goc de quay tam giac(theo do): ";
    cin >> x;
    tg.Quay(x* (M_PI / 180.0));
    cout << "\nTam giac sau khi quay la: " << endl;
    tg.Xuat();

    return 0;
}
