#include <bits/stdc++.h>
using namespace std;

class AnhNhiPhan {
private:
    int m, n;
    vector<vector<int>> maTran;

public:
    AnhNhiPhan(int chieuCao, int chieuRong, const vector<vector<int>> &duLieu);
    vector<vector<int>> TimHinhChuNhat();
};
