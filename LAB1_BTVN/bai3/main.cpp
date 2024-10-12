#include <bits/stdc++.h>
#include "PhanSo.cpp"
using namespace std;

void TimTapHopCon(vector<PhanSo> &phanSoArray, PhanSo &phanSoDich, vector<PhanSo> &ketQua, vector<PhanSo> &tamThoi, int idx) {
    if (idx == phanSoArray.size()) {
        PhanSo tich(1, 1);
        for (auto &ps : tamThoi) {
            tich = tich * ps;
        }
        if (tich == phanSoDich && (ketQua.empty() || tamThoi.size() < ketQua.size())) {
            ketQua = tamThoi;
        }
        return;
    }
    TimTapHopCon(phanSoArray, phanSoDich, ketQua, tamThoi, idx + 1);
    tamThoi.push_back(phanSoArray[idx]);
    TimTapHopCon(phanSoArray, phanSoDich, ketQua, tamThoi, idx + 1);
    tamThoi.pop_back();
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<PhanSo> phanSoArray(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << i + 1 << ":" << endl;
        phanSoArray[i].Nhap();
    }

    cout << "Nhap phan so dich: " << endl;
    int tuDich, mauDich;
    cin >> tuDich >> mauDich;
    PhanSo phanSoDich(tuDich, mauDich);

    sort(phanSoArray.begin(), phanSoArray.end());

    vector<PhanSo> ketQua, tamThoi;
    TimTapHopCon(phanSoArray, phanSoDich, ketQua, tamThoi, 0);

    if (!ketQua.empty()) {
        cout << "Tap hop con nho nhat co tich bang phan so dich: ";
        for (const auto &ps : ketQua) {
            ps.Xuat();
            cout << " ";
        }
        cout << endl;
    }
    else cout <<"Khong ton tai tap hop con nao co tich";

    return 0;
}
