#include "Room.h"
#include <bits/stdc++.h>
using namespace std;

Room::Room() : SoDem(0) {}

Room::Room(int soDem) : SoDem(soDem) {}

void Room::Nhap() {
    cout << "Nhap so dem: ";
    cin >> SoDem;
}
    