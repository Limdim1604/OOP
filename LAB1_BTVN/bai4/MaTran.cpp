#include <bits/stdc++.h>
#include "MaTran.h"
using namespace std;

MaTran::MaTran(int kichThuoc, const vector<vector<int>> &duLieu) : m(kichThuoc), duLieuBanDau(duLieu), maTranHienTai(duLieu) {}

void MaTran::BienDoi() {
    vector<vector<int>> maTranMoi(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int x = (2 * i + j) % m;
            int y = (i + j) % m;
            maTranMoi[x][y] = maTranHienTai[i][j];
        }
    }
    maTranHienTai = maTranMoi;
}

bool MaTran::KiemTraBanDau() const {
    return maTranHienTai == duLieuBanDau;
}

int MaTran::TinhChuKy() {
    int chuKy = 0;
    do {
        BienDoi();
        chuKy++;
    } while (!KiemTraBanDau());
    return chuKy;
}
