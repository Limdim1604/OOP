#include <bits/stdc++.h>
#include "QuanLy.h"
#include "KySu.h"
using namespace std;

int main() {
    QuanLy ql;
    KySu ks;
    cout << fixed << setprecision(4); // Không hiển thị chữ số thập phân

    cout << "Nhap thong tin Quan Ly:" << endl;
    ql.Nhap();

    cout << "\nNhap thong tin Ky Su:" << endl;
    ks.Nhap();

    cout << "\nThong tin Quan Ly:" << endl;
    ql.Xuat();

    cout << "\nThong tin Ky Su:" << endl;
    ks.Xuat();

    return 0;
}
