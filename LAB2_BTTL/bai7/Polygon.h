#include <bits/stdc++.h>
using namespace std;

class Polygon {
private:
    int n;                          // Số điểm của đa giác
    vector<pair<float, float>> Dinh; // Vector lưu tọa độ các điểm của đa giác

public:
    Polygon(int soDinh);
    void Nhap();
    float TinhDienTich() const;
};
