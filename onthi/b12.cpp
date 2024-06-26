#include<bits/stdc++.h>
using namespace std;
int sumOdd(vector<int> a, int i) {
    if (i == a.size()) return 0;
    else {
        if (a[i] % 2 != 0) return a[i] + sumOdd(a, i+1);
        else return sumOdd(a, i+1);
    }
}
int main() {
    vector<int> a = {9, 1,6,2,5, 4, 8};
    cout << sumOdd(a, 0);
}
