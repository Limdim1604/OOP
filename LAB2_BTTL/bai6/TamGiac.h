#include <bits/stdc++.h>
using namespace std;

class TamGiac {
private:
    float x1, y1; // Tọa độ điểm A
    float x2, y2; // Tọa độ điểm B
    float x3, y3; // Tọa độ điểm C

public:
    TamGiac(float x1, float y1, float x2, float y2, float x3, float y3);
    void TinhTien(float goc, float doDai);
    void Xuat() const;
};
