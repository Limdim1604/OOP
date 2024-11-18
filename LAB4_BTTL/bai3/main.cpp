#include <bits/stdc++.h>
#include "Bo.h"
#include "Cuu.h"
#include "De.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Khởi tạo seed cho hàm rand()

    int initialBo, initialCuu, initialDe;

    cout << "Nhap so luong Bo ban dau: ";
    cin >> initialBo;
    cout << "Nhap so luong Cuu ban dau: ";
    cin >> initialCuu;
    cout << "Nhap so luong De ban dau: ";
    cin >> initialDe;

    vector<GiaSuc*> trangTrai;

    // Tạo các gia súc ban đầu
    for (int i = 0; i < initialBo; ++i) {
        trangTrai.push_back(new Bo());
    }
    for (int i = 0; i < initialCuu; ++i) {
        trangTrai.push_back(new Cuu());
    }
    for (int i = 0; i < initialDe; ++i) {
        trangTrai.push_back(new De());
    }

    // a) Chủ nông trại đi vắng, gia súc đói và kêu
    cout << "\nGia suc dang doi, tieng keu nghe duoc trong nong trai:\n";
    for (size_t i = 0; i < trangTrai.size(); ++i) {
        cout << trangTrai[i]->Keu() << "\n";
    }
    cout << endl;

    // b) Thống kê sau một lứa sinh và một lượt cho sữa
    int totalBo = initialBo, totalCuu = initialCuu, totalDe = initialDe;
    int newBo = 0, newCuu = 0, newDe = 0;
    double totalMilk = 0.0;

    size_t currentSize = trangTrai.size();
    for (size_t i = 0; i < currentSize; ++i) {
        // Sinh con
        int offspring = trangTrai[i]->SinhCon();
        // Tạo gia súc mới và thêm vào trang trại
        for (int j = 0; j < offspring; ++j) {
            if (dynamic_cast<Bo*>(trangTrai[i])) {
                trangTrai.push_back(new Bo());
                ++newBo;
            } else if (dynamic_cast<Cuu*>(trangTrai[i])) {
                trangTrai.push_back(new Cuu());
                ++newCuu;
            } else if (dynamic_cast<De*>(trangTrai[i])) {
                trangTrai.push_back(new De());
                ++newDe;
            }
        }

        // Cho sữa
        double milk = trangTrai[i]->ChoSua();
        totalMilk += milk;
    }

    // Cập nhật tổng số gia súc
    totalBo += newBo;
    totalCuu += newCuu;
    totalDe += newDe;


    cout << fixed << setprecision(4);
    // Hiển thị thống kê
    cout << "\nThong ke sau mot luot sinh con va mot luot cho sua:\n";
    cout << "Tong so Bo: " << totalBo << endl;
    cout << "Tong so Cuu: " << totalCuu << endl;
    cout << "Tong so De: " << totalDe << endl;
    cout << "Tong so lit sua thu duoc: " << totalMilk << " lit" << endl;

    // Giải phóng bộ nhớ
    for (size_t i = 0; i < trangTrai.size(); ++i) {
        delete trangTrai[i];
    }
    trangTrai.clear();

    return 0;
}
