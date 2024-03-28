#include <bits/stdc++.h>
using namespace std;
int fiboLap(int n) {
    int f,f1=1,f2=1;
    for (int i = 3; i<=n;i++){
        f=f2+f1;
        f1=f2;
        f2=f;
    }
    return f;
}
int main(){
    cout << "Nhap so n: ";
    int n; cin >> n;
    cout << "So fibonaci thu " <<n<< " bang thuat toan lap la: ";
    cout << fiboLap(n);
}