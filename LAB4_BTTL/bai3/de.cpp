#include "De.h"
#include <bits/stdc++.h>

De::De() {
    TiengKeu = "Eeee";
}

De::~De() {}

int De::SinhCon() {
    // Dê có thể sinh từ 0 đến 2 con
    SoCon = rand() % 3;  // 0 đến 2
    return SoCon;
}

double De::ChoSua() {
    // Số lít sữa ngẫu nhiên từ 0 đến 10
    SoLitSua = rand() % 11;  // 0 đến 10
    return SoLitSua;
}

std::string De::Keu() {
    return TiengKeu;
}
