#include <iostream>
using namespace std;

struct NgayThangNam {
    int Ngay;
    int Thang;
    int Nam;
};

//năm nhuận (chia hết cho 400 và không chia hết cho 100) hoặc chia hết cho 4
bool laNamNhuan(int nam) {
    if (nam % 400 == 0) return true;
    if (nam % 100 == 0) return false;
    if (nam % 4 == 0) return true;
    return false;
}

// Hàm trả về số ngày trong tháng
int soNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return laNamNhuan(nam) ? 29 : 28;
        default:
            return 0; // Tháng không hợp lệ
    }
}

// Hàm kiểm tra ngày hợp lệ
bool ngayHopLe(NgayThangNam date) {
    if (date.Nam < 1 || date.Thang < 1 || date.Thang > 12 || date.Ngay < 1)
        return false;
    int maxNgay = soNgayTrongThang(date.Thang, date.Nam);
    if (maxNgay == 0) return false; // Tháng không hợp lệ
    if (date.Ngay > maxNgay)
        return false;
    return true;
}

// Hàm nhập ngày từ người dùng
void nhapNgay(NgayThangNam &date) {
    do {
        cout << "Nhap ngay: ";
        cin >> date.Ngay;
        cout << "Nhap thang: ";
        cin >> date.Thang;
        cout << "Nhap nam: ";
        cin >> date.Nam;
        if (!ngayHopLe(date)) {
            cout << "Ngay thang nam khong hop le. Vui long nhap lai.\n";
        }
    } while (!ngayHopLe(date));
}

// Hàm tính ngày kế tiếp
NgayThangNam ngayKeTiep(NgayThangNam date) {
    date.Ngay++;
    int maxNgay = soNgayTrongThang(date.Thang, date.Nam);
    if (date.Ngay > maxNgay) {
        date.Ngay = 1;
        date.Thang++;
        if (date.Thang > 12) {
            date.Thang = 1;
            date.Nam++;
        }
    }
    return date;
}

// Hàm tính ngày trước đó
NgayThangNam ngayTruocDo(NgayThangNam date) {
    date.Ngay--;
    if (date.Ngay < 1) {
        date.Thang--;
        if (date.Thang < 1) {
            date.Thang = 12;
            date.Nam--;
        }
        date.Ngay = soNgayTrongThang(date.Thang, date.Nam);
    }
    return date;
}

// Hàm tính ngày thứ bao nhiêu trong năm
int ngayThuTrongNam(NgayThangNam date) {
    int ngayThu = date.Ngay;
    for (int thang = 1; thang < date.Thang; thang++) {
        ngayThu += soNgayTrongThang(thang, date.Nam);
    }
    return ngayThu;
}

// Hàm xuất ngày
void xuatNgay(NgayThangNam date) {
    cout << date.Ngay << "/" << date.Thang << "/" << date.Nam;
}

int main() {
    NgayThangNam date;
    cout << "Nhap ngay thang nam hop le:\n";
    nhapNgay(date);

    // Tìm ngày kế tiếp
    NgayThangNam ngaySau = ngayKeTiep(date);
    cout << "Ngay ke tiep la: ";
    xuatNgay(ngaySau);
    cout << endl;

    // Tìm ngày trước đó
    NgayThangNam ngayTruoc = ngayTruocDo(date);
    cout << "Ngay truoc do la: ";
    xuatNgay(ngayTruoc);
    cout << endl;

    // Tính ngày thứ bao nhiêu trong năm
    int ngayThu = ngayThuTrongNam(date);
    cout << "Ngay ";
    xuatNgay(date);
    cout << " la ngay thu " << ngayThu << " trong nam." << endl;

    return 0;
}