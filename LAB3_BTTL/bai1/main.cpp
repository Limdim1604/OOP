#include "PhanSo.h"
#include <iostream>
using namespace std;

int main() {
    PhanSo ps1, ps2;
    
    cout << "Nhap phan so thu nhat:\n";
    cin >> ps1;

    cout << "Nhap phan so thu hai:\n";
    cin >> ps2;

    cout << "Tong: " << ps1 + ps2 << "\n";
    cout << "Hieu: " << ps1 - ps2 << "\n";
    cout << "Tich: " << ps1 * ps2 << "\n";
    
    if (!ps2.isZero()) {
        cout << "Thuong: " << ps1 / ps2 << "\n";
    } else {
        cout << "Khong the chia cho 0\n";
    }

    // Kiểm tra các toán tử so sánh
    if (ps1 == ps2) cout << "Hai phan so bang nhau\n";
    if (ps1 != ps2) cout << "Hai phan so khac nhau\n";
    if (ps1 >= ps2) cout << "Phan so thu nhat lon hon hoac bang phan so thu hai\n";
    if (ps1 <= ps2) cout << "Phan so thu nhat nho hon hoac bang phan so thu hai\n";
    if (ps1 > ps2) cout << "Phan so thu nhat lon hon phan so thu hai\n";
    if (ps1 < ps2) cout << "Phan so thu nhat nho hon phan so thu hai\n";

    return 0;
}
