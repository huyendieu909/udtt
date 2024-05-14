#include <bits/stdc++.h>
using namespace std;
void merge_sort(int s[], int f[], int n, int l, int r){
	if (l < r) {
		int m = l- (l-r)/2;
		merge_sort(s, f, n, l, m);
		merge_sort(s, f, n, m+1, r);
		int s2[n+1], f2[n+1];
		for (int i=m; i>=l; i--) s2[i] = s[i], f2[i] = f[i];
		for (int j = m+1; j<=r; j++) s2[r+m+1-j] = s[j], f2[r+m+1-j] = f[j];
		int i = l, j = r;
		for (int k = l; k<=r; k++) {
			if (f2[i] < f2[j]) s[k] = s2[i], f[k] = f2[i], i++;
			else s[k] = s2[j], f[k] = f2[j], j--;
		}
	}
}
int F6(int m[], int k[], int n, int b, int &p, vector<int> &d) {
	merge_sort(k, m, n, 0, n-1);
	int i =0;
	while (b - k[i] >=0) {
		b -= k[i];
		p += m[i];
		d.push_back(i);
		i++;
	}
	return p;
}
int main() {
	int n = 5;
	int m[] = {9, 7, 6, 5, 1};
	int k[] = {2, 1, 4, 3, 6};
	int b = 9;
	int p = 0;
	vector<int> d;
	p = F6(m,k,n,b,p,d);
	cout << p << "\n";
	for (int x : d) cout << m[x] << " ";
	cout << "\n";
	for (int x : d) cout << k[x] << " ";
}