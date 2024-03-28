#include <bits/stdc++.h>
using namespace std;
unordered_map<int, string> m;
int sum = 0;
void print_config(int x[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << m[x[i]] << " ";
    }
    cout << "\n";
}
void next_config(int x[], int n, int i) {
    int k = n;
    while (x[i] > x[k]) k--;
    swap(x[i], x[k]);
    int j = n;i++;
    while (i < j) {
        swap(x[i], x[j]); i++; j--;
    }
}
void list_config(int x[], int n) {
    int i;
    do {
        print_config(x,n);
        sum++;
        i = n-1;
        while (i > 0 && x[i] > x[i+1]) i--;
        if (i > 0) next_config(x,n,i);
    } while (i > 0);
}
int main(){
    m[1] = "tam";
    m[2] = "toan";
    m[3] = "trang";
    m[4] = "cong";
    m[5] = "trung";
    m[6] = "tu";
    int x[7] = {0};
    for (int i = 1; i<=6; i++) x[i] = i;
    list_config(x,6);
    cout << sum;
}