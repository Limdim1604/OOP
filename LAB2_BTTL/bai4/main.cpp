#include <bits/stdc++.h>
#include "ThiSinh.cpp"
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;

    vector<ThiSinh> dsThiSinh(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin thi sinh thu " << i + 1 << ":" << endl;
        dsThiSinh[i].Nhap();
    }

    bool coThiSinhTren15 = false;
    cout << "\nDanh sach thi sinh co tong diem tren 15 diem la:" << endl;
    for (const auto &thiSinh : dsThiSinh) {
        if (thiSinh.Tong() > 15) {
            coThiSinhTren15 = true;
            thiSinh.Xuat();
            cout << endl;
        }
    }
    if (!coThiSinhTren15) {
        cout << "Khong co thi sinh nao co tong diem tren 15 diem." << endl;}


    ThiSinh *thiSinhMax = &dsThiSinh[0];
    for (auto &thiSinh : dsThiSinh) {
        if (thiSinh.Tong() > thiSinhMax->Tong()) {
            thiSinhMax = &thiSinh;
        }
    }

    cout << "Thong tin thi sinh co tong diem cao nhat:" << endl;
    thiSinhMax->Xuat();

    return 0;
}
