#ifndef PREMIUM_H
#define PREMIUM_H

#include "Room.h"

class Premium : public Room {
private:
    double PhiDichVu; // Phí dịch vụ
public:
    Premium();
    Premium(int soDem, double phiDichVu);
    void Nhap();
    double TinhDoanhThu();
};

#endif
