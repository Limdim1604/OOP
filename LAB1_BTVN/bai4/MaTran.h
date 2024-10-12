#include <bits/stdc++.h>
using namespace std;

class MaTran {
private:
    int m;
    vector<vector<int>> duLieuBanDau;
    vector<vector<int>> maTranHienTai;

public:
    MaTran(int kichThuoc, const vector<vector<int>> &duLieu);
    void BienDoi();
    bool KiemTraBanDau() const;
    int TinhChuKy();
};
