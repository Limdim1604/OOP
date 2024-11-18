#ifndef GIASUC_H
#define GIASUC_H

#include <bits/stdc++.h>

class GiaSuc {
protected:
    int SoCon;           // Số con sinh ra
    double SoLitSua;     // Số lít sữa cho
    std::string TiengKeu; // Tiếng kêu

public:
    GiaSuc();
    virtual ~GiaSuc();
    virtual int SinhCon() = 0;        // Phương thức thuần ảo sinh con
    virtual double ChoSua() = 0;      // Phương thức thuần ảo cho sữa
    virtual std::string Keu() = 0;    // Phương thức thuần ảo kêu
};

#endif
