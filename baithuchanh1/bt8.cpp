#include <bits/stdc++.h>
using namespace std;
int O[100][100];
bool flag[100][100];
int so_mien = 0;
void taoMauThu(int O[100][100]) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 6;j++) {
			O[i][j] = 0;
			flag[i][j] = false;
		}
	}
	/*
		O mau nhu sau:
	1	1 1 0 0 0 1
	2	1 0 0 0 0 0
	3	1 0 0 1 1 0 
	4	0 1 1 0 0 1
	5	0 0 1 0 1 1
		
		1 2 3 4 5 6
	*/
	for (int i = 1; i <= 3; i++) O[i][1] = 1;
	O[1][2] = 1;
	O[4][2] = 1;
	O[4][3] = 1;
	O[5][3] = 1;
	O[3][4] = 1;
	O[3][5] = 1;
	O[5][5] = 1;
	O[1][6] = 1;
	O[4][6] = 1;
	O[5][6] = 1;
	//
	cout << "Lưới đã dùng để test: \n";
	for (int i = 1; i <= 5; i++) {
		cout << "\t";
		for (int j = 1; j <= 6;j++) {
			cout << O[i][j] << " ";
		}
		cout << "\n";
	}
}
void loang(int i, int j) {
	flag[i][j] = true;
	if (j > 1) {
		if (O[i][j-1] == O[i][j] && !flag[i][j-1]) loang(i,j-1);
	}
	if (i > 1) {
		if (O[i-1][j] == O[i][j] && !flag[i-1][j]) loang(i-1, j);
	}
	if (j < 6) {
		if (O[i][j+1] == O[i][j] && !flag[i][j+1]) loang(i, j+1);
	}
	if (i < 5) {
		if (O[i+1][j] == O[i][j] && !flag[i+1][j]) loang(i+1, j);
	}
}
int solve() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 6; j++) {
			if (O[i][j] == 1 && !flag[i][j]) {
				so_mien++;
				loang(i, j);
			}
		}
	}
	return so_mien;
}
int main() {
	system("chcp 65001");
	taoMauThu(O);
	cout << "Số miền liên thông tìm được là: " << solve();
}