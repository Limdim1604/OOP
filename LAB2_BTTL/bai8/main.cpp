#include <bits/stdc++.h>
#include "List.cpp"
using namespace std;

int main() {
    List list;
    int n;

    // Nhập chỉ thị cho đến khi gặp n = -1
    while (true) {
        cout << "Nhap chi thi (0: them phan tu, 1: xoa phan tu dau tien, 2: xoa tat ca, 3: thay doi, -1: thoat): ";
        cin >> n;

        if (n == -1) break; // Thoát vòng lặp nếu n = -1

        if (n == 0) {
            double x;
            cout << "Nhap gia tri x can them: ";
            cin >> x;
            list.Them(x);
        } else if (n == 1) {
            double x;
            cout << "Nhap gia tri x can xoa dau tien: ";
            cin >> x;
            list.XoaDauTien(x);
        } else if (n == 2) {
            double x;
            cout << "Nhap gia tri x can xoa tat ca: ";
            cin >> x;
            list.XoaTatCa(x);
        } else if (n == 3) {
            unsigned int x;
            double y;
            cout << "Nhap vi tri x can thay doi va gia tri y moi: ";
            cin >> x >> y;
            list.ThayDoi(x, y);
        }
    }

    // Xuất list hiện tại
    cout << "List hien tai: ";
    list.Xuat();

    return 0;
}
