#include <bits/stdc++.h>
using namespace std;
unordered_map<int, string> name;
void print_config(int k, int x[]){
    for (int i = 1; i <= k; i++) cout << name[x[i]] << " ";
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
        print_config(n, x);
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
    name[1] = "tam";
    name[2] = "toan";
    name[3] = "trang";
    name[4] = "cong";
    name[5] = "trung";
    name[6] = "tu";
    int n = 6, k = 4, x[k+1];
    list_config(4,6, x);
    // cout << "Hello world";
}