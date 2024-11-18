#ifndef DELUXE_H
#define DELUXE_H

#include "Room.h"

class Deluxe : public Room {
private:
    double PhiDichVu; // Phí dịch vụ
    double PhiPhucVu; // Phí phục vụ
public:
    Deluxe();
    Deluxe(int soDem, double phiDichVu, double phiPhucVu);
    void Nhap();
    double TinhDoanhThu();
};

#endif
