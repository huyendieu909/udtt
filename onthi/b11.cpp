#include <bits/stdc++.h>
using namespace std;
double sumArr (vector<double> a, int l, int r) {
    if (l == r) {
        return a[l];
    } else {
        int m = l-(l-r)/2;
        double sumLeft = sumArr(a, l, m);
        double sumRight = sumArr(a, m+1, r);
        double res = sumLeft + sumRight;
        return res;
    }
}
int main() {
    int n = 10;
    vector<double> a = {1.1, 2.2, 7.4, 8.5, 9.6, 6.1, 7.22, 4.12, 5.9, 10.222};
    cout << "Day a: ";
    for (double c: a) cout << c << " ";
    double sum = sumArr(a, 0, a.size()-1);
    cout << "\nTong tat ca cac so trong day a theo chia de tri: " << sum; 
}