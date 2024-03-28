#include <bits/stdc++.h>
using namespace std;
long sumIntString(int n){
    if (n == 0) return 0;
    return n%10+sumIntString(n/10);
}
int main() {
    long n;
    cout << "n = ";
    cin >> n;
    cout << sumIntString(n);
}