#include <bits/stdc++.h>
#include "AnhNhiPhan.cpp"
using namespace std;

int main() {
    int m, n;
    cout << "Nhap kich thuoc ma tran (m n): ";
    cin >> m >> n;

    vector<vector<int>> duLieu(m, vector<int>(n));
    cout << "Nhap ma tran nhi phan:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> duLieu[i][j];
        }
    }

    AnhNhiPhan anh(m, n, duLieu);
    vector<vector<int>> danhSachHinhChuNhat = anh.TimHinhChuNhat();

    if (danhSachHinhChuNhat.empty()) {
        cout << "Khong co hinh chu nhat thoa man." << endl;
    } else {
        cout << "Danh sach cac hinh chu nhat:" << endl;
        for (const auto &hcn : danhSachHinhChuNhat) {
            cout << "[" << hcn[0] << ", " << hcn[1] << ", " << hcn[2] << ", " << hcn[3] << "]" << endl;
        }
    }

    return 0;
}
