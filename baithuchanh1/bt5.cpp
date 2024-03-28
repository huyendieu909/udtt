#include <bits/stdc++.h>
using namespace std;

void next_config(int x[], int i, int n) {
    int k = n;
    while (x[k] < x[i]) k--;
    swap(x[k], x[i]);
    int j = n; i++;
    while (i < j) {
        swap(x[i], x[j]);
        i++;
        j--;
    }
}
void print_config(int x[], int n){
    for (int i = 1; i <= n; i++){
        cout << x[i] << " ";
    }
    cout << "\n";
}
void list_config(int n){
    int i, x[n+1] = {0};
    for (int i = 1;i<=n;i++) x[i] = i;
    do {
        print_config(x, n);
        i = n - 1;
        while (i > 0 && x[i] > x[i+1]) i--;
        if (i>0) {
            next_config(x, i, n);
        }
    } while(i>0);
}
int main() {
    int n;
    cout << "n = ";
    cin >> n;
    list_config(n);
}