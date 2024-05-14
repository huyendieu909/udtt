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
vector<int> F3 (int s[], int f[], int n, int &c) {
	vector<int> schedule;
	merge_sort(s,f,n,0,n-1);
	int last_finish = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] >= last_finish) {
			schedule.push_back(i);
			last_finish = f[i];
		}
	}
	c = schedule.size();
	return schedule;
}
int main() {
	int n = 5;
	int s[] = {4, 3, 1, 5, 2};
	int f[] = {6, 4, 5, 7, 3};
	int c;
	vector<int> res = F3(s,f, n, c);
	cout << c;
}