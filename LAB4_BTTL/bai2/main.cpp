#include <bits/stdc++.h>
#include "Deluxe.h"
#include "Premium.h"
#include "Business.h"
using namespace std;

int main() {
    // Khởi tạo 5 phòng
    Deluxe a, b;
    Premium c, d;
    Business e;

    // Nhập thông tin cho từng phòng
    cout << "Nhap thong tin phong Deluxe a:" << endl;
    a.Nhap();

    cout << "\nNhap thong tin phong Deluxe b:" << endl;
    b.Nhap();

    cout << "\nNhap thong tin phong Premium c:" << endl;
    c.Nhap();

    cout << "\nNhap thong tin phong Premium d:" << endl;
    d.Nhap();

    cout << "\nNhap thong tin phong Business e:" << endl;
    e.Nhap();

    // Tính doanh thu cho từng loại phòng
    double doanhThuDeluxe = a.TinhDoanhThu() + b.TinhDoanhThu();
    double doanhThuPremium = c.TinhDoanhThu() + d.TinhDoanhThu();
    double doanhThuBusiness = e.TinhDoanhThu();

    cout << fixed << setprecision(4);
    // Hiển thị doanh thu của từng loại phòng
    cout << "\nDoanh thu phong Deluxe: " << doanhThuDeluxe << endl;
    cout << "Doanh thu phong Premium: " << doanhThuPremium << endl;
    cout << "Doanh thu phong Business: " << doanhThuBusiness << endl;

    // Xác định loại phòng có doanh thu cao nhất
    double maxDoanhThu = doanhThuDeluxe;
    string loaiPhongMax = "Deluxe";

    if (doanhThuPremium > maxDoanhThu) {
        maxDoanhThu = doanhThuPremium;
        loaiPhongMax = "Premium";
    }
    if (doanhThuBusiness > maxDoanhThu) {
        maxDoanhThu = doanhThuBusiness;
        loaiPhongMax = "Business";
    }

    cout << "\nLoai phong co doanh thu cao nhat: " << loaiPhongMax
         << " voi doanh thu: " << maxDoanhThu << endl;

    return 0;
}
