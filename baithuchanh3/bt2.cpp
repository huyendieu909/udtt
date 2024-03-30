#include <bits/stdc++.h>
using namespace std;
void mergeSort(double a[], int l, int r, double b[]) {
    if (l < r) {
        int m = l - (l - r)/2;
        mergeSort(a, l, m, b);
        mergeSort(a, m+1, r, b);
        for (int i = m; i>=l; i--) b[i] = a[i];
        for (int j = m+1; j<=r; j++) b[r+m+1-j] = a[j];
        int i = l, j = r;
        for (int k = l; k <= r; k++) {
            if (b[i] < b[j]) a[k] = b[i], i++;
            else a[k] = b[j], j--;
        }
    }
}

int main(){
    double a[21] = {-1.5, -2.9, -4.4, 5.5,6.2,7.3,4, -11, -12, -16, 
                    10,14.8,4, 9, -5};
    double b[21];
    system("chcp 65001");
    cout << "Dãy 15 số: ";
    for (int i = 0; i<15;i++) cout << a[i] << " ";
    cout << "\nDãy đã sắp xếp trộn tăng dần: " ;
    mergeSort(a, 0, 14, b);
    for (int i=0;i<15;i++) cout << a[i] << " ";
}