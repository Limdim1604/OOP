#include <bits/stdc++.h>
using namespace std;

struct phanso{
    int tu, mau;
};
int main() {
    phanso a,b;
    cout << "Nhap tu so va mau so thu nhat: \n";
    cin>>a.tu>>a.mau;
    cout << "Nhap tu so va mau so thu hai: \n";
    cin>>b.tu>>b.mau;
    if ((double)a.tu/a.mau > (double)b.tu/b.mau) 
         cout << "Phan so lon nhat la" << a.tu << "/" << a.mau;
    else if ((double)a.tu/a.mau < (double)b.tu/b.mau) 
         cout << "Phan so lon nhat la" << b.tu << "/" << b.mau;
    else cout << "Hai phan so bang nhau";
    return 0;
}