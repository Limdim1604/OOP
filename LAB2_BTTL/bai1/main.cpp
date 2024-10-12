#include <bits/stdc++.h>
#include "Diem.cpp"
using namespace std;

int main() {
    Diem d1;                 // Gọi hàm khởi tạo mặc định
    double xb, yb;
    cout << "Nhap toa do diem d2: xb yb = \n";
    cin >> xb >> yb;
    Diem d2(xb, yb);           // Gọi hàm khởi tạo với tham số
    Diem d3(d2);             // Gọi hàm khởi tạo sao chép

    cout << "Diem d1 duoc tao mac dinh: ";
    d1.Xuat();

    cout << "Diem d2: ";
    d2.Xuat();

    cout << "Diem d3 sao chep diem d2: ";
    d3.Xuat();

    int x, y;
    cout << "Nhap toa do moi cho diem d1: x y = ";
    cin >> x >> y;
    d1.SetHoanhDo(x);
    d1.SetTungDo(y);
    cout << "Diem d1 sau khi thay doi toa do: \n";
    d1.Xuat();

    double xt, yt;
    cout << "Nhap vector tinh tien: xt yt = \n";
    cin >> xt >> yt;
    cout << "Diem d1 sau khi tinh tien ",xt," ",yt," : \n";
    d1.TinhTien(xt, yt);
    
    d1.Xuat();

    return 0;
}
