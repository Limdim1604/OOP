#include "ThoiGian.h"
#include <iostream>
using namespace std;

int main() {
    ThoiGian tg1, tg2;

    // Nhập thời gian đầu tiên
    cout << "Nhap thoi gian thu nhat:\n";
    cin >> tg1;

    // Nhập thời gian thứ hai
    cout << "Nhap thoi gian thu hai:\n";
    cin >> tg2;

    // Hiển thị thời gian vừa nhập
    cout << "Thoi gian thu nhat: " << tg1 << "\n";
    cout << "Thoi gian thu hai: " << tg2 << "\n";

    // Cộng và trừ hai thời gian
    cout << "Tong hai thoi gian: " << tg1 + tg2 << "\n";
    cout << "Hieu hai thoi gian: " << tg1 - tg2 << "\n";

    // Cộng và trừ giây vào thời gian
    cout << "Thoi gian thu nhat sau khi cong 120 giay: " << tg1 + 120 << "\n";
    cout << "Thoi gian thu nhat sau khi tru 60 giay: " << tg1 - 60 << "\n";

    // Sử dụng toán tử tăng giảm ++, --
    cout << "Thoi gian thu nhat sau khi tang 1 giay (prefix): " << ++tg1 << "\n";
    cout << "Thoi gian thu hai sau khi giam 1 giay (prefix): " << --tg2 << "\n";

    // Reset tg1 and tg2 for postfix demonstration
    tg1--; // Trở lại thời gian ban đầu
    tg2++; // Trở lại thời gian ban đầu

    cout << "Thoi gian thu nhat sau khi tang 1 giay (postfix): " << tg1++ << "\n";
    cout << "Thoi gian thu nhat hien tai sau khi tang (postfix): " << tg1 << "\n";
    cout << "Thoi gian thu hai sau khi giam 1 giay (postfix): " << tg2-- << "\n";
    cout << "Thoi gian thu hai hien tai sau khi tang (posfix): " << tg2 << "\n";

    // So sánh thời gian
    if (tg1 == tg2) cout << "Hai thoi gian bang nhau\n";
    if (tg1 != tg2) cout << "Hai thoi gian khac nhau\n";
    if (tg1 > tg2) cout << "Thoi gian thu nhat lon hon thoi gian thu hai\n";
    if (tg1 < tg2) cout << "Thoi gian thu nhat nho hon thoi gian thu hai\n";
    if (tg1 >= tg2) cout << "Thoi gian thu nhat lon hon hoac bang thoi gian thu hai\n";
    if (tg1 <= tg2) cout << "Thoi gian thu nhat nho hon hoac bang thoi gian thu hai\n";

    return 0;
}
