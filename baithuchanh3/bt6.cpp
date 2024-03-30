#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
    if (a == -1 && b == -1) return -1;
    if (a == -1) return b;
    if (b == -1) return a;
    return (a < b) ? a:b;
}
int minEven(int a[], int l, int r) {
    if (l >= r) {
        if (a[l] % 2 == 0) return a[l];
        else return -1;
    }
    int m = l - (l-r)/2;
    int minEvenLeft = minEven(a, l, m);
    int minEvenRight = minEven(a, m+1, r);
    int res = min(minEvenLeft, minEvenRight);
    return res;
}
int main() {
    int a[21] = {-1, -2, -4, 5,6,7,4, -11, -12, -16, 
                    10,14,4, 9, -5, 2, -8, -22, 13, -9};
    system("chcp 65001");
    cout << "Dãy 20 số: ";
    for (int i = 0; i<20;i++) cout << a[i] << " ";
    int m = minEven(a, 0, 19);
    if (m == -1) cout << "Không có số chẵn trong dãy";
    else {
        cout << "\nSố chẵn nhỏ nhất: " << m;
    }
}