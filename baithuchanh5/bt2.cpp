#include <bits/stdc++.h>
using namespace std;
void solve(int w[], int v[], int n, int m, int &maxV, vector<int> &index) {
	/*
		0	1	2	3	4	5	6	7	8	9	10	11	12
	0	0	0	0	0	0	0	0	0	0	0	0	0	0
4	1	0	0	0	0	1	1	1	1	1	1	1	1	1
5	2	0	0	0x	0	1	2	2	2	2	3	3	3	3
1	3	0	4	4	4x	4	5	7	7	7	7	8	8	8
6	4	0	4	4	4	4	5	7	7	7	7	8	8	9
2	5	0	4	5	9	9	9	9	10	12	12x	12	12	13
3	6	0	4	5	9	12	13	17	17	17	17	18	20	20x

3	2	1	5
8	5	4	3
	*/
	int mat[n+1][m+1];
	for (int i = 0; i <= m; i++) {
		mat[0][i] = 0;
	}
	for (int i = 1; i<= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (w[i] > j) mat[i][j] = mat[i-1][j];
			else mat[i][j] = max(mat[i-1][j], mat[i-1][j-w[i]] + v[i]);
		}
	}
	maxV = mat[n][m]; 
	int i = n, j = m;
	while (i != 0) {
		if (mat[i][j] != mat[i-1][j]) index.push_back(i), j -= w[i];
		i--;
	}
}
int main(){
	system("chcp 65001");
	int n = 6;
	int w[] = {0, 4, 5, 1, 6, 2, 3};
	int v[] = {0, 1, 3, 4, 2, 5, 8};
	int m = 12;
	int maxV;
	vector<int> index;
	solve(w,v,n,m,maxV, index);
	cout << "Số gói hàng cần lấy: " << index.size() << '\n';
	cout << maxV << "\n";
	for (int c: index) cout << w[c] << " ";
	cout << "\n";
	for (int c: index) cout << v[c] << " ";
}