#include <bits/stdc++.h>
using namespace std;
int sumOdd(int n, int x[]) {
    if (n == 0) return 0;
    else if (x[n] % 2 != 0) return x[n] + sumOdd(--n, x);
    return sumOdd(--n,x);
}
int main() {
    int n;
    cout << "n = ";
    cin >> n;
    int x[n+1];
    for (int i = 1; i <= n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }
    cout << sumOdd(n, x);
}