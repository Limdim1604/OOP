#ifndef BUSINESS_H
#define BUSINESS_H

#include "Room.h"

class Business : public Room {
public:
    Business();
    Business(int soDem);
    void Nhap();
    double TinhDoanhThu();
};

#endif
