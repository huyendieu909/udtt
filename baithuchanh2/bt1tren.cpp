#include <bits/stdc++.h>
using namespace std;
int ucln(int a, int b){
    if (b == 0) return a;
    else return ucln(b, a%b);
}
int main(){
    int a, b;
    system("chcp 65001");
    cout << "Nhập số thứ nhất: ";
    cin >> a;
    cout << "Nhập số thứ hai: ";
    cin >> b;
    cout << "Ước chung lớn nhất của 2 số bằng đệ quy: ";
    cout << ucln(a, b);
}