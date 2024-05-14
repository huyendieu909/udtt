#include <bits/stdc++.h>
using namespace std;
int solve(int n, int m){
	int next[n+1], cur[n+1];
	cur[0] = 1;
	for (int i=1; i<=n; i++) cur[i] = 0;
	for (int i = 1; i<=m;i++) {
		for (int j = 0; j <= n; j++) {
			if(i > j) {
				next[j] = cur[j];
			} else {
				next[j] = cur[j] + next[j-i];
			}
		}
		for (int i=0; i<=n; i++) {
			cur[i] = next[i];
		}
	}
	return cur[n];
}
int main() {
	int n = 6, m = 6;
	cout << solve(n,m);
}


