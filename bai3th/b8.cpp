#include <bits/stdc++.h>
using namespace std;
int maxM[1000][1000]; 
void trace(int n, int l, int m[], int k[]){
    vector<int> v;
    int i = n, j = l;
    while (i > 0) {
        if (maxM[i][j] == maxM[i-1][j]) {
            i--;
        } else {
            v.push_back(i);
            j = j - k[i];
            i--;
        }
    }
    cout << "Các kiện hàng được lấy có khối lượng và thể tích lần lượt là: ";
    for (int i : v) {
        cout << "{" << m[i] << ", " << k[i] << "} ";  
    }
    cout << "\nTổng kiện hàng cần lấy: " << v.size();
}
void solve(int n, int l, int m[], int k[]){
    for (int i = 0; i <= n;i++) {
        for (int j = 0; j <= l; j++) {
            maxM[i][j] = 0;
        }
    }
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= l; j++) {
            if (j < k[i]) maxM[i][j] = maxM[i-1][j];
            else {
                maxM[i][j] = max(maxM[i-1][j], maxM[i-1][j-k[i]] + m[i]);
            }
        }
    }
    cout << "Khối lượng hàng lớn nhất chở được là: " << maxM[n][l] << "\n";
    trace(n, l, m, k);
}
int main(){
    system("chcp 65001");
    int l;
    cout << "Nhập kích thước thùng xe: ";
    cin >> l;
    int n;
    cout << "Nhập số kiện hàng: ";
    cin >> n;
    int m[n+1] = {0}, k[n+1] = {0};
    cout << "Nhập khối lượng và kích thước từng kiện hàng (khối lượng_kích thước): ";
    for (int i = 1; i <= n;i++) cin >> k[i] >> m[i];
    solve(n, l, m, k);
}