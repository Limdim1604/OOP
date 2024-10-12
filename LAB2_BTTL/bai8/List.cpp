#include <bits/stdc++.h>
#include "List.h"
using namespace std;

List::List() : array(nullptr), size(0) {}

List::~List() {
    delete[] array;
}

// Thêm phần tử vào cuối list
void List::Them(double x) {
    double *newArray = new double[size + 1];
    for (unsigned int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    newArray[size] = x;
    delete[] array;
    array = newArray;
    size++;
}

// Xóa phần tử đầu tiên có giá trị x
void List::XoaDauTien(double x) {
    for (unsigned int i = 0; i < size; i++) {
        if (array[i] == x) {
            double *newArray = new double[size - 1];
            for (unsigned int j = 0, k = 0; j < size; j++) {
                if (j != i) {
                    newArray[k++] = array[j];
                }
            }
            delete[] array;
            array = newArray;
            size--;
            return;
        }
    }
}

// Xóa tất cả phần tử có giá trị x
void List::XoaTatCa(double x) {
    unsigned int newSize = 0;
    for (unsigned int i = 0; i < size; i++) {
        if (array[i] != x) {
            newSize++;
        }
    }
    double *newArray = new double[newSize];
    for (unsigned int i = 0, j = 0; i < size; i++) {
        if (array[i] != x) {
            newArray[j++] = array[i];
        }
    }
    delete[] array;
    array = newArray;
    size = newSize;
}

// Thay đổi phần tử thứ idx bằng y
void List::ThayDoi(unsigned int idx, double y) {
    if (idx < size) {
        array[idx] = y;
    }
}

// Xuất list theo định dạng [a,b,c,...]
void List::Xuat() const {
    cout << "[";
    for (unsigned int i = 0; i < size; i++) {
        cout << array[i];
        if (i < size - 1) cout << ",";
    }
    cout << "]" << endl;
}
