#include <bits/stdc++.h>
using namespace std;

class HocSinh {
private:
    string hoTen;
    float diemToan;
    float diemVan;
    float diemAnh;
    float diemTrungBinh;
    string xepLoai;

    // Kiểm tra họ tên không chứa chữ số
    bool kiemTraHoTen(const string& ten) {
        for (char c : ten) {
            if (isdigit(c))
                return false;
        }
        return !ten.empty();
    }

    // Kiểm tra điểm hợp lệ (0 <= điểm <= 10)
    bool kiemTraDiem(float diem) {
        return diem >= 0.0f && diem <= 10.0f;
    }

    // Tính điểm trung bình
    void tinhDiemTrungBinh() {
        diemTrungBinh = ((2 * diemToan) + diemVan + diemAnh) / 4.0f;
    }

    // Xếp loại học sinh
    void xepLoaiHocSinh() {
        if (diemTrungBinh >= 9.0f)
            xepLoai = "Xuat sac";
        else if (diemTrungBinh >= 8.0f)
            xepLoai = "Gioi";
        else if (diemTrungBinh >= 6.5f)
            xepLoai = "Kha";
        else if (diemTrungBinh >= 5.0f)
            xepLoai = "Trung binh";
        else
            xepLoai = "Yeu";
    }

public:
    // Hàm nhập thông tin học sinh
    void nhapThongTin() {
        cin.ignore(); // Xóa bộ đệm trước khi nhập chuỗi
        // Nhập và kiểm tra họ tên
        do {
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
            if (!kiemTraHoTen(hoTen))
                cout << "Ho ten khong hop le. Vui long nhap lai.\n";
        } while (!kiemTraHoTen(hoTen));

        // Nhập và kiểm tra điểm Toán
        do {
            cout << "Nhap diem Toan (0 - 10): ";
            cin >> diemToan;
            if (!kiemTraDiem(diemToan))
                cout << "Diem khong hop le. Vui long nhap lai.\n";
        } while (!kiemTraDiem(diemToan));

        // Nhập và kiểm tra điểm Văn
        do {
            cout << "Nhap diem Van (0 - 10): ";
            cin >> diemVan;
            if (!kiemTraDiem(diemVan))
                cout << "Diem khong hop le. Vui long nhap lai.\n";
        } while (!kiemTraDiem(diemVan));

        // Nhập và kiểm tra điểm Anh
        do {
            cout << "Nhap diem Anh (0 - 10): ";
            cin >> diemAnh;
            if (!kiemTraDiem(diemAnh))
                cout << "Diem khong hop le. Vui long nhap lai.\n";
        } while (!kiemTraDiem(diemAnh));

        tinhDiemTrungBinh();
        xepLoaiHocSinh();
    }

    // Hàm xuất thông tin học sinh
    void xuatThongTin() const {
        cout << fixed << setprecision(2);
        cout << "Ho ten: " << hoTen << endl;
        cout << "Diem Toan: " << diemToan << endl;
        cout << "Diem Van: " << diemVan << endl;
        cout << "Diem Anh: " << diemAnh << endl;
        cout << "Diem trung binh: " << diemTrungBinh << endl;
        cout << "Xep loai: " << xepLoai << endl;
    }

    // Getter cho điểm trung bình
    float getDiemTrungBinh() const {
        return diemTrungBinh;
    }

    // Getter cho điểm Toán
    float getDiemToan() const {
        return diemToan;
    }

    // Getter cho họ tên
    string getHoTen() const {
        return hoTen;
    }
};

class QuanLyHocSinh {
private:
    vector<HocSinh> danhSachHocSinh;

public:
    // Nhập thông tin cho n học sinh
    void nhapDanhSachHocSinh() {
        int n;
        cout << "Nhap so luong hoc sinh: ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cout << "\nNhap thong tin cho hoc sinh thu " << i + 1 << ":\n";
            HocSinh hs;
            hs.nhapThongTin();
            danhSachHocSinh.push_back(hs);
        }
    }

    // Xuất danh sách học sinh
    void xuatDanhSachHocSinh() const {
        for (const auto& hs : danhSachHocSinh) {
            hs.xuatThongTin();
            cout << "-------------------------\n";
        }
    }

    // Tìm và xuất thông tin học sinh có điểm trung bình cao nhất
    void timHocSinhDiemCaoNhat() const {
        if (danhSachHocSinh.empty()) {
            cout << "Danh sach hoc sinh rong.\n";
            return;
        }
        float maxDiemTB = danhSachHocSinh[0].getDiemTrungBinh();
        vector<HocSinh> hocSinhMax;
        // Tìm điểm trung bình cao nhất
        for (const auto& hs : danhSachHocSinh) {
            if (hs.getDiemTrungBinh() > maxDiemTB) {
                maxDiemTB = hs.getDiemTrungBinh();
                hocSinhMax.clear();
                hocSinhMax.push_back(hs);
            }
            else if (hs.getDiemTrungBinh() == maxDiemTB) {
                hocSinhMax.push_back(hs);
            }
        }

        cout << "\nHoc sinh co diem trung binh cao nhat (" << maxDiemTB << "):\n";
        for (const auto& hs : hocSinhMax) {
            hs.xuatThongTin();
            cout << "-------------------------\n";
        }
    }

    // Tìm kiếm học sinh theo tên (không phân biệt hoa thường, không cần nhập đầy đủ)
    void timKiemHocSinhTheoTen() const {
        if (danhSachHocSinh.empty()) {
            cout << "Danh sach hoc sinh rong.\n";
            return;
        }
        cin.ignore();
        string tuKhoa;
        cout << "Nhap ten hoc sinh can tim: ";
        getline(cin, tuKhoa);

        // Chuyển tuKhoa về chữ thường
        transform(tuKhoa.begin(), tuKhoa.end(), tuKhoa.begin(), ::tolower);

        vector<HocSinh> ketQua;

        for (const auto& hs : danhSachHocSinh) {
            string tenHocSinh = hs.getHoTen(); 
            // Chuyển tenHocSinh về chữ thường
            transform(tenHocSinh.begin(), tenHocSinh.end(), tenHocSinh.begin(), ::tolower);
            if (tenHocSinh.find(tuKhoa) != string::npos) {
                ketQua.push_back(hs);
            }
        }
        // Xuất kết quả
        if (ketQua.empty()) {
            cout << "Khong tim thay hoc sinh voi tu khoa \"" << tuKhoa << "\".\n";
        }
        else {
            cout << "\nKet qua tim kiem:\n";
            for (const auto& hs : ketQua) {
                hs.xuatThongTin();
                cout << "-------------------------\n";
            }
        }
    }

    // Xuất danh sách học sinh có điểm Toán thấp nhất
    void xuatHocSinhDiemToanThapNhat() const {
        if (danhSachHocSinh.empty()) {
            cout << "Danh sach hoc sinh rong.\n";
            return;
        }
        float minDiemToan = danhSachHocSinh[0].getDiemToan();
        vector<HocSinh> hocSinhMin;
        // Tìm điểm Toán thấp nhất
        for (const auto& hs : danhSachHocSinh) {
            if (hs.getDiemToan() < minDiemToan) {
                minDiemToan = hs.getDiemToan();
                hocSinhMin.clear();
                hocSinhMin.push_back(hs);
            }
            else if (hs.getDiemToan() == minDiemToan) {
                hocSinhMin.push_back(hs);
            }
        }

        cout << "\nDanh sach hoc sinh co diem Toan thap nhat (" << minDiemToan << "):\n";
        for (const auto& hs : hocSinhMin) {
            hs.xuatThongTin();
            cout << "-------------------------\n";
        }
    }
};

int main() {
    QuanLyHocSinh qlhs;
    qlhs.nhapDanhSachHocSinh();

    cout << "\n===== Danh sach hoc sinh =====\n";
    qlhs.xuatDanhSachHocSinh();

    qlhs.timHocSinhDiemCaoNhat();

    qlhs.xuatHocSinhDiemToanThapNhat();

    qlhs.timKiemHocSinhTheoTen();

    

    return 0;
}