#include <bits/stdc++.h>
#include "Diem.cpp"
using namespace std;

int main() {
    float hoanh, tung;
    int n;

    // Nhập hoành độ và tung độ của điểm
    cout << "Nhap hoanh do va tung do cua diem: ";
    cin >> hoanh >> tung;
    Diem diem(hoanh, tung);

    // Nhập số lượng chỉ thị cần thực hiện
    cout << "Nhap so luong chi thi can thuc hien: ";
    cin >> n;

    // Thực hiện từng chỉ thị
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Chi thi 1: Nhan doi hoanh do va tung do" << endl;
        cout << "Chi thi 2: Gan diem ve goc toa do" << endl;
        cout << "Chi thi 3: Tinh tien diem" << endl;
        cout << "Nhap chi thi: ";
        cin >> x;

        // Kiểm tra giá trị của chỉ thị và thực hiện tương ứng
        if (x == 1) {
            // Chỉ thị 1: Nhân đôi hoành độ và tung độ
            diem.NhanDoi();
            diem.Xuat();
        } else if (x == 2) {
            // Chỉ thị 2: Gán điểm về gốc tọa độ
            diem.GanGocToaDo();
            diem.Xuat();
        } else if (x == 3) {
            // Chỉ thị 3: Nhập hướng tịnh tiến (k) và độ tịnh tiến (d)
            int k;
            float d;
            cout << "Nhap huong tinh tien (0 la x, khac 0 la y) va do tinh tien: ";
            cin >> k >> d;
            diem.TinhTien(k, d);
            diem.Xuat();
        }
        // Nếu chỉ thị khác 1, 2, 3, không làm gì cả
    }

    // Xuất tọa độ cuối cùng của điểm sau khi thực hiện tất cả chỉ thị
    cout << "Toa do cuoi cung cua diem: ";
    diem.Xuat();

    return 0;
}
