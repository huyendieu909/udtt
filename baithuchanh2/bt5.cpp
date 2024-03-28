#include <bits/stdc++.h>
using namespace std;
void show(int n, int x[]){
	for (int i = 1; i<=n; i++) {
		cout << x[i];
	}
	cout << "\n";
}
void Try(int k, int n, int x[]){
	for (int i = 0; i <= 1; i++) {
		x[k] = i;
		if (k == n) show(n, x);
		else {
			Try(k+1, n, x);
		}	
	}
}

int main() {
	system("chcp 65001");
	int n;
	cout << "Nhập n: ";
	cin >> n;
	int x[n+1];
	cout << "Dãy nhị phân độ dài n sinh được bằng quay lui: \n";
	Try(1, n, x);
}