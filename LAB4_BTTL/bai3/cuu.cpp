#include "Cuu.h"
#include <cstdlib>  // For rand()
#include <ctime>

Cuu::Cuu() {
    TiengKeu = "Beee";
}

Cuu::~Cuu() {}

int Cuu::SinhCon() {
    // Cừu có thể sinh từ 0 đến 2 con
    SoCon = rand() % 3;  // 0 đến 2
    return SoCon;
}

double Cuu::ChoSua() {
    // Số lít sữa ngẫu nhiên từ 0 đến 5
    SoLitSua = rand() % 6;  // 0 đến 5
    return SoLitSua;
}

std::string Cuu::Keu() {
    return TiengKeu;
}
