#include <bits/stdc++.h>
using namespace std;

void next_config(int x[], int i, int k) {
    x[i]++;
    i++;
    while (i <= k) 
    {
        x[i] = x[i-1] + 1;
        i++;
    }
}

void print_config(int x[], int k) {
    for (int i = 1;i <= k; i++) cout << x[i] << " ";
    cout << "\n";
}

void list_config(int x[], int i, int k, int n){
    do {
        print_config(x, k);
        i = k;
        while(i > 0 && x[i] == n-k+i) {
            i--;
        }
        if(i>0) {
            next_config(x, i, k);
        }
    } while (i > 0);
}

int main() {
    int k = 6;
    int n = 9;
    int x[k+1] = {0};
    for (int i = 1; i<=k; i++) x[i] = i;
    int i;
    list_config(x, i, k, n);
}