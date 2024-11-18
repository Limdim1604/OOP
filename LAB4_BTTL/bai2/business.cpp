#include "Business.h"
#include <bits/stdc++.h>
using namespace std;

Business::Business() : Room() {}

Business::Business(int soDem) : Room(soDem) {}

void Business::Nhap() {
    Room::Nhap();
}

double Business::TinhDoanhThu() {
    return SoDem * 300000;
}
