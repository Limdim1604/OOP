#include <bits/stdc++.h>
#include "Diem.cpp"
using namespace std;

class DaGiac {
private:
    int n;           // Số đỉnh của đa giác
    Diem *Dinh;      // Mảng các đỉnh của đa giác

public:
    DaGiac();
    DaGiac(int soDinh);
    ~DaGiac();
    void Nhap();
    void Xuat() const;
    void TinhTien(double dx, double dy);
    void PhongTo(double scale);
    void ThuNho(double scale);
    void Quay(double rad);
};
