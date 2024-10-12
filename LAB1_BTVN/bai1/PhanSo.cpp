#include <bits/stdc++.h>
#include "PhanSo.h"
using namespace std;

PhanSo::PhanSo() : tuSo(0), mauSo(1){}
PhanSo::PhanSo(int tu, int mau) : tuSo(tu), mauSo(mau){}
void PhanSo::Nhap(){
    cout << "Nhap tu cua phan so: ";
    cin >> tuSo;
    cout << "Nhap mau cua phan so: ";
    cin >> mauSo;
    while(mauSo == 0){
        cout << "Mau so khong duoc la so 0, vui long nhap lai: ";
        cin >> mauSo;
    }
}
void PhanSo::Xuat(){
    cout << tuSo << "/" << mauSo;
}
