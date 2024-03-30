#include <bits/stdc++.h>
using namespace std;
double maxArr(double a[], int l, int r){
    if (l >= r) return a[l];
    int m = l - (l-r)/2;
    double maxLeft = maxArr(a, l, m);
    double maxRight = maxArr(a, m+1, r);
    double maxA = max(maxLeft, maxRight);
    return maxA;
}
int main(){
    double a[21] = {-1.5, -2.9, -4.4, 5.5,6.2,7.3,4, -11, -12, -16, 
                    10,14.8,4, 9, -5};
    system("chcp 65001");
    cout << "Dãy 15 số: ";
    for (int i = 0; i<15;i++) cout << a[i] << " ";
    cout << "\nGiá trị lớn nhất: " << maxArr(a, 0, 14);
}