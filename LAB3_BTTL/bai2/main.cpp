#include "SoPhuc.h"
#include <iostream>
using namespace std;

int main() {
    SoPhuc sp1, sp2;

    // Nhập số phức đầu tiên
    cout << "Nhap so phuc thu nhat:\n";
    cin >> sp1;

    // Nhập số phức thứ hai
    cout << "Nhap so phuc thu hai:\n";
    cin >> sp2;

    // Thực hiện các phép toán và in kết quả
    cout << "Tong: " << sp1 + sp2 << "\n"; // Phép cộng hai số phức
    cout << "Hieu: " << sp1 - sp2 << "\n"; // Phép trừ hai số phức
    cout << "Tich: " << sp1 * sp2 << "\n"; // Phép nhân hai số phức
    cout << "Thuong: " << sp1 / sp2 << "\n"; // Phép chia hai số phức

    // Kiểm tra các toán tử so sánh
    if (sp1 == sp2) cout << "Hai so phuc bang nhau\n"; // So sánh bằng
    if (sp1 != sp2) cout << "Hai so phuc khac nhau\n"; // So sánh khác

    return 0;
}
