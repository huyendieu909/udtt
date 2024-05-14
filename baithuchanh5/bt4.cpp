#include <bits/stdc++.h>
using namespace std;
void Q4(int n, int c[], int s[], int m, int &t) {
    int f[m+1];
    f[0] = 0;
    for (int i=1; i<=m;i++) f[i] = 0;
    int min ;
    for (int i = 1; i<=m;i++){
        min = INT_MAX;
        for (int j = 1; j <=n; j++){
            if (f[i-c[j]] + 1< min && c[j] <= i) {
                min = f[i-c[j]] + 1;
                s[i] = j;
            }
        }
        f[i] = min;
    }
    cout << f[m] << "\n";
    int j = s[m];
    int i = m;
    while (j != 0) {
        cout << c[j] << " ";
        i = i-c[j];
        j=s[i];
    }
}
/*

        0   1   2   3   4   5   6   7   8   9   
0   0   0   +   +   +   +   +   +   +   +   +
1   1   0   1   2   3   4   5   6   7   8   9
2   2   0   1   1   2   2   3   3   4   4   5
5   3   0   1   1   2   2   1   2   2   3   3



10  4
20  5
50  6
100 7
200 8
500 9

*/
int main() {
    int n = 9, m = 1975, t;
    int c[] = {0,1,2,5,10,20,50,100,200,500};
    int s[m+1]  ;
    Q4(n,c,s,m,t);
}