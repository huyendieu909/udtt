//8h50
#include <bits/stdc++.h>
using namespace std;
double sumOdd (vector<double> a, int l, int r) {
    if (l == r) {
        if (a[l] > 0) return a[l];
        else return 0;
    } else {
        int m = l-(l-r)/2;
        double sumOddLeft = sumOdd(a, l, m);
        double sumOddRight = sumOdd(a, m+1, r);
        double res = sumOddLeft + sumOddRight;
        return res;
    }
}
int main () {
    vector<double> a = {-1.1, 2.2, 3.3, -4.4, -5.5, 6.6, 7.7, 8.8, 9.9, 10.11};
    cout << "Day a: ";
    for (double c:a) cout << c << " ";
    double sum = sumOdd(a, 0, a.size()-1);
    cout << "\nTong so duong trong a: " << sum;
}
// 8h58