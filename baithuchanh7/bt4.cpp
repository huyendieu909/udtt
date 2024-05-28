#include <bits/stdc++.h>
using namespace std;
struct dienthoai{
	string nhanhieu;
	int kichthuoc;
	double giaban;
};
void Q1 (int s, vector<dienthoai> d, int &x, vector<dienthoai> &a) {
	double mat[d.size()+1][s+1];
	for (int i = 0; i <= d.size(); i++) {
		for (int j = 0; j <= s; j++) {
			mat[i][j] = 0;
		}
	}
	for (int i = 1; i<= d.size(); i++) {
		for (int j = 1; j <= s; j++) {
			if (d[i-1].kichthuoc > j) mat[i][j] = mat[i-1][j];
			else {
				mat[i][j] = max(mat[i-1][j], mat[i-1][j-d[i-1].kichthuoc] + d[i-1].giaban);
			}
		}
	}
//	for (int i = 0; i <= d.size(); i++) {
//		for (int j = 0; j <= s; j++) {
//			cout << setprecision(10) << mat[i][j] << "\t";
//		}
//		cout << '\n';
//	}
	int i = d.size(), j = s;
	while (i != 0) {
		if (mat[i][j] != mat[i-1][j]) {
			a.push_back(d[i-1]);
			j = j - d[i-1].kichthuoc;
		}
		i--;
	}
	x = a.size();
}
void HienThiKetQua (int x, vector<dienthoai> a) {
	cout << x << '\n';
	cout << "Nhan hieu" << setw(27) << "Gia ban\n";
	for (dienthoai c: a) {
		cout << setw(9) << c.nhanhieu << setw(27) << setprecision(10) << c.giaban << "\n";
	}
}
int main(){
	int s = 15;
	vector<dienthoai> d = {{"Nokia", 12, 4000000},
						   {"Samsung", 2, 2000000},
						   {"IPhone", 1, 1000000},
						   {"Xiaomi", 1, 2000000},
						   {"Huawei", 4, 10000000}};
	int x = 0;
	vector<dienthoai> a;
	Q1(s,d,x,a);
	HienThiKetQua(x,a);
}