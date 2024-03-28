#include <bits/stdc++.h>
using namespace std;
void print_config(int n, int x[]){
    for (int i = 1;i<=n;i++) cout << x[i];
    cout << "\n";
}
void next_config(int i, int n, int x[]){
    x[i] = 1;
    i++;
    while (i <= n) {
        x[i] = 0;
        i++;
    }
}
void list_config(int n){
    int x[n+1];
    for (int i = 0; i<=n;i++) x[i] = 0;
    int i;
    do {
        print_config(n, x);
        i = n;
        while (i > 0 && x[i] == 1) i--;
        if (i > 0) next_config(i, n, x);
    } while (i > 0);
}
int main(){
    system("chcp 65001");
    cout << "Nhập độ dài n của chuỗi cần sinh: ";
    int n;
    cin >> n;
    list_config(n);
}