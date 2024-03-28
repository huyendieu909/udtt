#include <bits/stdc++.h>
using namespace std;
int uclnKhuDeQuy(int a, int b){
    int r = a%b;
    while (r != 0) {
        a = b;
        b = r;
        r = a%b;
    };
    return b;
}
int main() {
    int a, b;
    system("chcp 65001");
    cout << "Nhập số thứ nhất: ";
    cin >> a;
    cout << "Nhập số thứ hai: ";
    cin >> b;
    cout << "Ước chung lớn nhất của 2 số bằng khử đệ quy: ";
    cout << uclnKhuDeQuy(a, b);
}