#ifndef ROOM_H
#define ROOM_H

class Room {
protected:
    int SoDem; // Số đêm
public:
    Room();
    Room(int soDem);
    virtual void Nhap();
    virtual double TinhDoanhThu() = 0; // Phương thức thuần ảo
    virtual ~Room() {} // Destructor ảo
};

#endif
