#include <bits/stdc++.h>
#include "MaTran.cpp"
using namespace std;

int main() {
    int m;
    cout << "Nhap kich thuoc ma tran vuong m: ";
    cin >> m;

    vector<vector<int>> duLieu(m, vector<int>(m));
    cout << "Nhap cac phan tu cua ma tran:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> duLieu[i][j];
        }
    }

    MaTran maTran(m, duLieu);
    int chuKy = maTran.TinhChuKy();
    cout << "He so chu ky k cua phep bien doi Arnold's Cat Map la: " << chuKy << endl;

    return 0;
}
