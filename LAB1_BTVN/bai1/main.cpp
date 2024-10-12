#include <bits/stdc++.h>
#include "PhanSo.cpp"
using namespace std;

int main()
{
    int n;
    cout << "Nhap so luong n phan so: ";
    cin >> n;
    PhanSo NhoNhat(INT_MAX, 1);
    PhanSo LonNhat(0, 1);
    for(int i = 1; i <= n; i++){
        PhanSo ps;
        ps.Nhap();
        if(ps < NhoNhat) NhoNhat = ps;
        if(LonNhat < ps) LonNhat = ps;
    }
    cout << "Phan so nho nhat la: ";
    NhoNhat.Xuat();
    cout << "\nPhan so lon nhat la: ";
    LonNhat.Xuat();
    return 0;
}
