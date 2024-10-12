#include <bits/stdc++.h>
using namespace std;

class List {
private:
    double *array;           // Con trỏ quản lý mảng động
    unsigned int size;       // Kích thước hiện tại của list

public:
    List();
    ~List();
    void Them(double x);         // Thêm phần tử vào cuối list
    void XoaDauTien(double x);   // Xóa phần tử đầu tiên có giá trị x
    void XoaTatCa(double x);     // Xóa tất cả phần tử có giá trị x
    void ThayDoi(unsigned int idx, double y); // Thay đổi phần tử thứ idx thành y
    void Xuat() const;           // Xuất list theo định dạng [a,b,c,...]
};
