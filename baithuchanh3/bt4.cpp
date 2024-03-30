#include <bits/stdc++.h>
using namespace std;
double power(double a, int n) {
    if (n == 0) return 1;
    else if (n == 1) return a;
    else {
        double x = power(a, n/2);
        double res = x*x;
        if (n % 2 != 0) res*=a;
        return res;
    }
}
int main() {
    double a;
    int n;
    cout << "a = ";
    cin >> a;
    cout << "a ^ n = " << power(a, n);
}