#include <bits/stdc++.h>
using namespace std;

class PhanSo{
private:
    int tuSo, mauSo;
public:
    PhanSo();
    PhanSo(int tu, int mau);
    void Nhap();
    void Xuat();
    bool operator < (PhanSo const b) const{
        return (long long) tuSo * b.mauSo < (long long)b.tuSo * mauSo;
    }
};
