#include <bits/stdc++.h>
using namespace std;
void print_config(int k, int x[]){
    for (int i = 1; i <= k; i++) cout << x[i] << " ";
    cout << "\n"; 
}
void next_config(int i, int k, int x[]){
    x[i]++;
    i++;
    while (i <= k) {
        x[i] = x[i-1] + 1;
        i ++;
    }
}
void list_config(int k, int n, int x[]){
    int i;
    for (int i = 1; i<=k;i++) x[i] = i;
    do {
        print_config(k, x);
        i = k;
        while (i > 0 && x[i] == n - k + i){
            i--;
        }
        if (i > 0) {
            next_config(i, k, x);
        }
    } while (i > 0);
}
int main(){
    int n, k, x[k+1];
    cout << "n = ";
    cin >> n;
    cout << "k = ";
    cin >> k;
    list_config(k,n, x);
    // cout << "Hello world";
}