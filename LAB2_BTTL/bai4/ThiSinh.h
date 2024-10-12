#include <bits/stdc++.h>
using namespace std;

class ThiSinh {
private:
    string Ten;      // Tên thí sinh
    string MSSV;     // Mã số sinh viên
    int iNgay, iThang, iNam;  // Ngày, tháng, năm sinh
    float fToan, fVan, fAnh;  // Điểm Toán, Văn, Anh

public:
    ThiSinh();
    void Nhap();
    void Xuat() const;
    float Tong() const;
    string getMSSV() const;
};
