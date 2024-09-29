#include <bits/stdc++.h>
using namespace std;

struct PhanSo {
    int tuSo;
    int mauSo;
};
//hàm nhập phân số
void nhapPhanSo(PhanSo &ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tuSo;
    do {
        cout << "Nhap mau so (khac 0): ";
        cin >> ps.mauSo;
        if (ps.mauSo == 0) {
            cout << "Mau so phai khac 0. Vui long nhap lai.\n";
        }
    } while (ps.mauSo == 0);
}
//hàm xuất phân số
void xuatPhanSo(const PhanSo &ps) {
    if (ps.mauSo == 0) {
        cout << "Phan so khong hop le (mau so bang 0).\n";
    } else if (ps.tuSo == 0) {
        cout << "0\n";
    } else if (abs (ps.mauSo) == 1) cout << ps.tuSo << "\n";
    else cout<<ps.tuSo<<"/"<<ps.mauSo << "\n";
    
}
//hàm tối giản phân số
void toiGianPhanSo(PhanSo &ps) {
    int ucln = __gcd(ps.tuSo, ps.mauSo);
    ps.tuSo /= ucln;
    ps.mauSo /= ucln;
    if (ps.mauSo < 0) {
        ps.tuSo = -ps.tuSo;
        ps.mauSo = -ps.mauSo;
    }
}
//các phép toán với hai phân số
PhanSo cong(const PhanSo &ps1, const PhanSo &ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    toiGianPhanSo(ketQua);
    return ketQua;
}

PhanSo tru(const PhanSo &ps1, const PhanSo &ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    toiGianPhanSo(ketQua);
    return ketQua;
}

PhanSo nhan(const PhanSo &ps1, const PhanSo &ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.tuSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    toiGianPhanSo(ketQua);
    return ketQua;
}

PhanSo chia(const PhanSo &ps1, const PhanSo &ps2) {
    if (ps2.tuSo == 0) {
        cout << "Loi chia cho 0.\n";
        exit(1);
    }
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.tuSo;
    toiGianPhanSo(ketQua);
    return ketQua;
}

int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu nhat:\n";
    nhapPhanSo(ps1);
    cout << "Nhap phan so thu hai:\n";
    nhapPhanSo(ps2);

// xuất các phép toán với hai phân số
    PhanSo tong = cong(ps1, ps2);
    cout << "Tong: ";
    xuatPhanSo(tong);

    PhanSo hieu = tru(ps1, ps2);
    cout << "Hieu: ";
    xuatPhanSo(hieu);

    PhanSo tich = nhan(ps1, ps2);
    cout << "Tich: ";
    xuatPhanSo(tich);

    PhanSo thuong = chia(ps1, ps2);
    cout << "Thuong: ";
    xuatPhanSo(thuong);

    return 0;
}