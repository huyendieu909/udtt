#include <bits/stdc++.h>
using namespace std;
void merge_sort(int w[], int l, int r);
void xep_xe(int n, int k[], int sl[], int m, int &count){
//	sort(k, k+n, greater<int>());
	merge_sort(k, 0, n-1);
	int i = 0;
	while (i < n && m > 0) {
		sl[i] ++;
		m -= k[i];
		count++;
		i++;
	}
	if (m > 0) cout << "Dùng hết xe nhưng vẫn còn " << m << " tấn hàng cần chuyển.\n";
	else {
		cout << "Cần dùng ít nhất " << count << " xe, gồm những xe có tải trọng (tấn): ";
		for (int i = 0; i<n; i++) {
			if (sl[i] > 0) cout << k[i] << " ";
		}
	}
}
void merge_sort(int w[], int l, int r) {
	if (l < r) {
		int m = l - (l-r)/2;
		merge_sort(w, l, m);
		merge_sort(w, m+1, r);
		int k1[100];
		for (int i=m; i>=l; i--) k1[i] = w[i];
		for (int j=m+1; j<=r; j++) k1[r+m+1-j] = w[j];
		int i = l, j = r;
		for (int k = l; k<=r; k++) {
			if (k1[i] < k1[j]) w[k] = k1[j], j--;
			else w[k] = k1[i], i++;
		}
	}
}
int main(){
	system("chcp 65001");
	int n = 5;
	int k[] = {8,3,1,5,7};
	int sl[5] = {0};
	int m = 10;
	int count = 0;
	cout << "Giả sử có " << n << " xe và các xe có tải trọng là ";
	for (int i = 0; i<n; i++) cout << k[i] << " ";
	cout << "tấn và cần chuyển " << m << " tấn hàng\n";
	xep_xe(n,k,sl, m, count);
}