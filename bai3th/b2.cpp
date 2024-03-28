#include <bits/stdc++.h>
using namespace std;
int solve(int n, int m, int x[]){
    sort(x, x+m);
    // for (int i =0; i< m;i++) cout << x[i] << " ";
    // cout<<"\n";
    int i = 0;
    int sum = 0;
    while (n - x[i] >=0 && i < m) {
        n-=x[i];
        sum++;
        i++;
    }
    return sum;
}
int main(){
    int n, m;
    cin >> n >> m;
    int x[m];
    for (int i = 0; i < m; i++) cin >> x[i];
    cout << solve(n,m,x);
}