#include <bits/stdc++.h>
using namespace std;
long fib(int i, long d[]) {
    if (i == 1 || i == 2) d[i] = 1;
    else if (d[i] < 0) d[i] = fib(i-1, d) + fib(i-2, d);
    return d[i];
}
int main() {
    int n;
    cout << "n = ";
    cin >> n;
    long d[n+1];
    for (int i = 0; i<=n;i++) d[i] = -1;
    cout << fib(n, d);
}