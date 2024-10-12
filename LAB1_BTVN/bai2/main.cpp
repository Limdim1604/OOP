#include <bits/stdc++.h>
#include "PhanSo.cpp"
using namespace std;

int main()
{
    int n, k;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    cout << "Nhap gia tri k: ";
    cin >> k;

    vector<PhanSo> danhSachPhanSo(n);
    for(int i = 0; i < n; i++){
        cout << "Nhap phan so thu " << i + 1 << ":" << endl;
        danhSachPhanSo[i].Nhap();
    }

    // Sắp xếp phân số theo thứ tự tăng dần
    sort(danhSachPhanSo.begin(), danhSachPhanSo.end());

    // Kiểm tra và xuất phân số bé thứ k
    if(k <= n){
        cout << "Phan so be thu " << k << ": ";
        danhSachPhanSo[k - 1].Xuat();
        cout << endl;
    }

    // Kiểm tra và xuất phân số lớn thứ k
    if(k <= n){
        cout << "Phan so lon thu " << k << ": ";
        danhSachPhanSo[n - k].Xuat();
        cout << endl;
    }

    return 0;
}
