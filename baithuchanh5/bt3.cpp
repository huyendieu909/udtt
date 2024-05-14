#include <bits/stdc++.h>
using namespace std;
void Q3(int a[], int n, int L[], int T[]){
    int jmax;
    for (int i = n; i>= 0; i--) {
        jmax = n+1;
        for (int j = i+1; j <= n+1; j++) {
            if (a[j] > a[i] && L[j] > L[jmax]) jmax = j;
        }
        L[i] = L[jmax] + 1;
        T[i] = jmax;
    }
}
void res(int a[], int n, int T[], vector<int> &ress) {
    int k = T[0];
    while (k != n+1) {
        ress.push_back(a[k]);
        k = T[k];
    }
}
int main() {
    int n = 10;
    int a[n+2] = {-2147482648, 5, 2, 3, 4, 9, 10, 5, 6, 7, 8, 2147482648};
    int L[n+2], T[n+2];
    L[n+1] = 1;
    vector<int> ress;
    Q3(a,n,L,T);
    res(a,n,T,ress);
    for (int x: ress) cout << x << " ";
    cout << "\n" << ress.size();
}