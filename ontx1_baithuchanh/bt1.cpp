#include <bits/stdc++.h>
using namespace std;
void show(vector<string> N, char G[], int c[], int n) {
    for (int i = 0; i<n;i++) cout << G[i] << ":" << N[c[i+1]-1] << " "; 
    cout << "\n";
}

void next_config(int c[], int i, int n) {
    int l = n;
    while (c[i] > c[l]) l--;
    swap(c[i], c[l]);
    int r = n; l= ++i;
    while (l<r) {
        swap(c[l], c[r]); l++; r--;
    }
}
void A1 (vector<string> &N, char G[], int n, int &count) {
    int c[n+1] = {0};
    for (int i = 1; i<=n; i++) c[i] = i;
    int i = n;
    do {
        show(N, G, c, n);
        count++;
        i = n - 1;
        while (i > 0 && c[i] > c[i+1]) i--;
        if (i > 0) {
            next_config(c, i, n);
        }
    } while (i > 0);
}
void A2(int k, vector<string> &N, char G[], int id[], int n, bool flag[], int &count) {
    for (int i = 1; i <= n; i++) {
        if (!flag[i]) {
            id[k] = i;
            if (k == n) show(N,G,id,n), count++;
            else {
                flag[i] = true;
                A2(k+1, N, G, id, n, flag, count); 
                flag[i] = false;
            }
        }
    }
}
int main() {
    char G[] = {'A', 'B', 'C', 'D'};
    vector<string> N = {"Tung", "Cuc", "Truc", "Mai"}; 
    int n = 4, count=0;
    int id[n+1] = {0};
    bool flag[n+1] = {false};
    A1(N,G,n, count);
    cout << "Có " << count << " cách xếp\n";
    count = 0;
    cout << "\n";
    A2(1, N, G, id, n, flag, count);
    cout << "Có " << count << " cách xếp\n";
}