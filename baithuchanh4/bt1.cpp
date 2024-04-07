#include <bits/stdc++.h>
using namespace std;
vector<int> coin_changing (int n, vector<int> c, int m){
    vector<int> s;
    sort(c.rbegin(), c.rend());
    int i = 0;
    while (i < n && m >= 0) {
        int a = m / c[i];
        s.push_back(a);
        m -= s[i] * c[i];
        i++;
    }
    if (m > 0) cout << "Không đổi được";
    return s;
}
int main(){
    vector<int> s;
    vector<int> c;
    c.push_back(100);
    c.push_back(25);
    c.push_back(10);
    c.push_back(5);
    c.push_back(1);
    int n = 5, m = 34;
    s = coin_changing(n, c, m);
    cout << "m = " << m;
    cout << "\nn = 5\n";
    for (int k : c) cout << k << " ";
    cout << "\n";
    for (int b : s) cout << b << " ";
}