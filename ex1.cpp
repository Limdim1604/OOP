#include <bits/stdc++.h>
using namespace std;

struct phanso{
    int tu, mau;
    void rutgon(){
        int temp = __gcd(tu, mau);
        tu /= temp;
        mau /= temp;
        //hàm đổi dấu từ mẫu sang tử để nhìn cho đẹp
        if (mau < 0){
            tu = -tu;
            mau = -mau;
        }
    }
};

int main() {
    phanso a;
    cin>>a.tu>>a.mau;
    if (a.mau == 0) {cout << "Khong xac dinh";
                     return 0;
    }
    a.rutgon();
    if (abs (a.mau) == 1) cout << a.tu;
    else cout<<a.tu<<"/"<<a.mau;
    return 0;
}