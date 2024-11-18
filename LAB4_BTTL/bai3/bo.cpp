#include "Bo.h"
#include <bits/stdc++.h>

Bo::Bo() {
    TiengKeu = "Booo";
}

Bo::~Bo() {}

int Bo::SinhCon() {
    // Bò có thể sinh từ 0 đến 1 con
    SoCon = rand() % 2;  // 0 hoặc 1
    return SoCon;
}

double Bo::ChoSua() {
    // Số lít sữa ngẫu nhiên từ 0 đến 20
    SoLitSua = rand() % 21;  // 0 đến 20
    return SoLitSua;
}

std::string Bo::Keu() {
    return TiengKeu;
}
