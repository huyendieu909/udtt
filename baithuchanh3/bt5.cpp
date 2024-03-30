#include <bits/stdc++.h>
using namespace std;
double sumArr(double a[], int l, int r){
    if (l >= r) {
        if (a[l] > 0) return a[l];
        else return 0;
    }
    int m = (l+r)/2;
    double sumLeft = sumArr(a, l, m);
    double sumRight = sumArr(a, m+1, r);
    double sum = sumLeft + sumRight;
    return sum;
}
int main() {
    double a[21] = {-1.5, -2.9, -4.4, 5.5,6.2,7.3,4, -11, -12, -16, 
                    10,14,4, 9, -5, 2, -8, -22, 13, -9};
    system("chcp 65001");
    cout << "Dãy 20 số: ";
    for (int i = 0; i<20;i++) cout << a[i] << " ";
    cout << "\nTổng các số dương: " << sumArr(a, 0, 19);
}