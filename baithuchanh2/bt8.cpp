#include<bits/stdc++.h>
using namespace std;
void show (int O[][9]) {
    for (int i = 1; i<=8;i++) {
        for (int j = 1; j<= 8; j++) {
            cout << O[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}
bool isValid(int O[][9], int x, int y) {
    for (int i = 1; i<= x-1;i++) {
        if (O[i][y] == 1) return false;
    }
    int i = 1;
    while (x - i >= 1 && y-i>=1){
        if (O[x-i][y-i] == 1) return false;
        i++;
    }
    i=1;
    while (x-i >= 1 && y+i <= 8) {
        if (O[x-i][y+i] == 1) return false;
        i++;
    }
    return true;
}
void Try(int O[][9], int k){
    if (k == 9) show(O);
    for (int i = 1; i <= 8; i++) {
        if (isValid(O,k,i)){
            O[k][i] = 1;
            Try(O, k+1);
            O[k][i] = 0;
        }
    }
}
int main() {
    int O[9][9] = {0};
    Try(O,1);
}