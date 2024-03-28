#include <bits/stdc++.h>
using namespace std;
int X[10], Y[10];
int bo_dem = 1;
int so_cach = 0;
int O[100][100];
void tao_nuoc_di() {
	/*
		-2		-1		0		1		2
	-2	  	   -2,-1		  -2,1
	-1  -1,-2						  -1,2
	 0					x
	 1   1,-2						   1,2
	 2			2,-1		   2,1
	*/
	//Tạo được 8 nước đi đánh dấu từ 1 đến 8
	X[1] = -2; Y[1] = -1;
	X[2] = -2; Y[2] = 1;
	X[3] = -1; Y[3] = -2;
	X[4] = -1; Y[4] = 2;
	X[5] = 1; Y[5] = -2;
	X[6] = 1; Y[6] = 2;
	X[7] = 2; Y[7] = -1;
	X[8] = 2; Y[8] = 1;
}
void show(int O[][100], int n) {
	for (int i = 1;i<=n;i++) {
		for (int j = 1; j<=n;j++) {
			cout << O[i][j] << "\t";
		}
		cout << "\n\n";
	}
	cout << "\n\n\n";
}
bool validate(int x, int X, int y, int Y, int n) {
	if (x + X < 1 || y + Y < 1 || x + X > n || y + Y > n || O[x+X][y+Y] != 0) return false;
	return true; 
}
void Try(int a, int b, int n) {
	O[a][b] = bo_dem;
	if (bo_dem == n*n){
		so_cach++;
		cout << "Cách " << so_cach << ": \n";
		show(O, n);
	}
	else {
		for (int i = 1; i <= 8; i++) {
			if (validate(a, X[i], b, Y[i], n)) {
				bo_dem++;
				Try(a+X[i], b+Y[i], n);
				bo_dem--;
			}
		}
		if (bo_dem == 1 && so_cach == 0) cout << "Hết cách";
	}
	O[a][b] = 0;
}
int main() {
	system("chcp 65001");
	cout << "Nhập kích thước bàn cờ vua n: ";
	int n;
	cin >> n;
	cout << "Nhập vị trí xuất phát (nhập vào 2 số cách nhau dấu cách là tọa độ của điểm xuất phát): ";
	int xpX, xpY;
	cin >> xpX >> xpY;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j<=n;j++) {
			O[i][j] = 0;
		}
	}
	tao_nuoc_di();
	Try(xpX, xpY, n);
}