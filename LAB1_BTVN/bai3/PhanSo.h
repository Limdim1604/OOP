#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tuSo, mauSo;
public:
    PhanSo();
    PhanSo(int tu, int mau);
    void Nhap();
    void Xuat() const;
    bool operator < (const PhanSo &b) const;
    PhanSo operator * (const PhanSo &b) const;
    bool operator == (const PhanSo &b) const;
};
