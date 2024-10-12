#include <bits/stdc++.h>
using namespace std;

class Diem {
private:
    double Hoanh;
    double Tung;

public:
    Diem();
    Diem(double Hoanh, double Tung);
    Diem(const Diem &x);
    void Xuat();
    double GetTungDo();
    double GetHoanhDo();
    void SetTungDo(double Tung);
    void SetHoanhDo(double Hoanh);
    void TinhTien(double dx, double dy);
    void Quay(double rad);
};
