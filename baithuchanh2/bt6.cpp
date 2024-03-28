#include <bits/stdc++.h>
using namespace std;
void show(int x[], int n ) {
	for (int i = 1; i<=n; i++) {
		cout << x[i] << " ";
	}
	cout << "\n";
}
void Try(int x[], int k, int n, bool flag[]) {
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			x[k] = i;
			if (k == n) show(x, n);
			else {
				flag[i] = true;
				Try(x, k+1, n, flag);
				flag[i] = false; 
			}
		} 
	}
}
int main() {
	system("chcp 65001");
	int n;
	cout << "Nhập độ dài dãy hoán vị: ";
	cin >> n;
	int x[n+1];
	bool flag[n+1];
	for (int i = 1; i <= n; i++) flag[i] = false;
	// Mẫu ở đây sẽ dùng hoán vị dãy từ 1 đến n
	Try(x, 1, n, flag);
}