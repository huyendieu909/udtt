#include <bits/stdc++.h>
using namespace std;

void next_config(int x[], int i, int n){
    x[i] = 1;
    i++;
    while (i <= n)
    {
        x[i]=0;
        i++;
    }
}
void print_config(int x[], int n){
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << "\n";
}
void list_config(int x[], int i, int n) {
    do {
        print_config(x,n);
        i = n;
        while (i > 0 && x[i] == 1)
        {
            i--;
        }
        if (i > 0) {
            next_config(x, i, n);
        }
    } while(i > 0);
}
int main() {
    int n = 5;
    int x[n+1] = {0};
    int i;
    list_config(x,i,n);
}