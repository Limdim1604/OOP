#include "NgayThangNam.h"
#include <iostream>
using namespace std;

int main() {
    NgayThangNam date1, date2;

    // Nhập ngày tháng năm đầu tiên
    cout << "Nhap ngay thang nam thu nhat:\n";
    cin >> date1;

    // Nhập ngày tháng năm thứ hai
    cout << "Nhap ngay thang nam thu hai:\n";
    cin >> date2;

    // Hiển thị ngày tháng năm vừa nhập
    cout << "Ngay thang nam thu nhat: " << date1 << "\n";
    cout << "Ngay thang nam thu hai: " << date2 << "\n";

    // Cộng và trừ số ngày
    cout << "Ngay thang nam thu nhat sau khi cong 10 ngay: " << date1 + 10 << "\n";
    cout << "Ngay thang nam thu nhat sau khi tru 5 ngay: " << date1 - 5 << "\n";

    // Hiệu giữa hai ngày
    cout << "So ngay giua hai ngay thang nam: " << date1 - date2 << " ngay\n";

    // Sử dụng toán tử tăng giảm ++, --
    cout << "Ngay thang nam thu nhat sau khi tang 1 ngay (prefix): " << ++date1 << "\n";
    cout << "Ngay thang nam thu hai sau khi giam 1 ngay (prefix): " << --date2 << "\n";

    // Reset date1 and date2 for postfix demonstration
    date1--; // Trở lại ngày ban đầu
    date2++; // Trở lại ngày ban đầu

    cout << "Ngay thang nam thu nhat sau khi tang 1 ngay (postfix): " << date1++ << "\n";
    cout << "Ngay thang nam thu nhat hien tai sau khi tang (postfix): " << date1 << "\n";
    cout << "Ngay thang nam thu hai sau khi giam 1 ngay (postfix): " << date2-- << "\n";
    cout << "Ngay thang nam thu hai hien tai sau khi giam (postfix): " << date2 << "\n";

    // So sánh ngày tháng năm
    if (date1 == date2) cout << "Hai ngay thang nam bang nhau\n";
    if (date1 != date2) cout << "Hai ngay thang nam khac nhau\n";
    if (date1 > date2) cout << "Ngay thang nam thu nhat lon hon ngay thang nam thu hai\n";
    if (date1 < date2) cout << "Ngay thang nam thu nhat nho hon ngay thang nam thu hai\n";
    if (date1 >= date2) cout << "Ngay thang nam thu nhat lon hon hoac bang ngay thang nam thu hai\n";
    if (date1 <= date2) cout << "Ngay thang nam thu nhat nho hon hoac bang ngay thang nam thu hai\n";

    return 0;
}
