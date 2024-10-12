#include <bits/stdc++.h>
#include "AnhNhiPhan.h"
using namespace std;

AnhNhiPhan::AnhNhiPhan(int chieuCao, int chieuRong, const vector<vector<int>> &duLieu) 
    : m(chieuCao), n(chieuRong), maTran(duLieu) {}

vector<vector<int>> AnhNhiPhan::TimHinhChuNhat() {
    vector<vector<int>> danhSachHinhChuNhat;
    vector<vector<bool>> daDuyet(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (maTran[i][j] == 1 && !daDuyet[i][j]) {
                int chieuRong = 0, chieuCao = 0;
                
                // Xác định chiều rộng hình chữ nhật
                while (j + chieuRong < n && maTran[i][j + chieuRong] == 1)
                    chieuRong++;
                
                // Xác định chiều cao hình chữ nhật
                bool valid = true;
                while (i + chieuCao < m && valid) {
                    for (int k = 0; k < chieuRong; k++) {
                        if (maTran[i + chieuCao][j + k] == 0) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) chieuCao++;
                }

                // Đánh dấu các ô đã duyệt trong hình chữ nhật
                if (chieuRong >= 2 && chieuCao >= 2) {
                    for (int x = 0; x < chieuCao; x++) {
                        for (int y = 0; y < chieuRong; y++) {
                            daDuyet[i + x][j + y] = true;
                        }
                    }
                    danhSachHinhChuNhat.push_back({i, j, chieuRong, chieuCao});
                }
            }
        }
    }

    return danhSachHinhChuNhat;
}
