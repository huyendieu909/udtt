#include <bits/stdc++.h>
using namespace std;
void solve(int n, int k[], int m){
    sort(k, k+n, greater<int>());
    int res = 0, i = 0;
    while (m - k[i] >= 0 && i < n){
        m -= k[i];
        res++;
        i++;
    }
    if (i < n && m > 0) {
        res++;
        i++;
    }
    cout << "Số xe ít nhất cần dùng: " << res;
    cout << "\nNhững xe được dùng có tải trọng: ";
    for (int j = 0; j<i;j++) {
        cout << k[j] << " "; 
    }
}
int main() {
    system("chcp 65001");
    int n;
    cout << "Nhập số xe tải của công ti a: ";
    cin >> n;
    int k[n];
    cout << "Nhập tải trọng mỗi xe (cách nhau bởi dấu cách): ";
    for (int i = 0; i<n;i++) cin >> k[i];
    int m;
    cout << "Nhập khối lượng hàng cần vận chuyển: ";
    cin >> m;
    solve(n,k,m);
}