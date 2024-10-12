#include <bits/stdc++.h>
using namespace std;

class Diem {
private:
    float Hoanh;  // Hoành độ (tọa độ x)
    float Tung;   // Tung độ (tọa độ y)

public:
    Diem();
    Diem(float hoanh, float tung);
    void Xuat() const;         // Xuất tọa độ điểm dưới dạng (x, y)
    void NhanDoi();            // Nhân đôi hoành độ và tung độ
    void GanGocToaDo();        // Gán điểm về gốc tọa độ (0, 0)
    void TinhTien(int k, float d);  // Tịnh tiến theo hướng và độ tịnh tiến d
};
