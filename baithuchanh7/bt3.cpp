#include <bits/stdc++.h>
using namespace std;
struct quatban {
	string tenhang;
	string mausac;
	double giaban;
};
void merge_sort(vector<quatban> &d, int l, int r) {
	if (l < r) {
		int m = l-(l-r)/2;
		merge_sort(d, l, m);
		merge_sort(d, m+1, r);
		quatban a[d.size()];
		for (int i = m; i>=l; i--) a[i] = d[i];
		for (int j = m+1; j<=r; j++) a[r+m+1-j] = d[j];
		int i = l, j = r;
		for (int k = l; k <= r; k++) {
			if (a[i].giaban < a[j].giaban) d[k] = a[j], j--;
			else d[k] = a[i], i++;
		}
	}
}
bool F3 (double &p, vector<quatban> d, int &q, vector<quatban> &t) {
	merge_sort(d, 0, d.size()-1);
	int i = 0;
	while (p >= 0 && i < d.size()) {
		q++;
		t.push_back(d[i]);
		p -= d[i].giaban;
		i++;
	}
	if (p < 0) return true;
	else return false;
}
void HienThiKetQua (int p, int q, vector<quatban> t) {
	if (p < 0) {
		cout << "---So luong quat it nhat da ban: " << q << '\n';
		cout << "---Danh sach quat da ban--- \n";
		cout << "Ten hang san xuat" << setw(20) << "Gia ban" << '\n';
		for (int i = 0; i<t.size(); i++) {
			cout << setw(17) << t[i].tenhang << setw(20) << t[i].giaban << '\n';
		}
	} else {
		cout << "Ban het quat van khong duoc so tien lon hon p.";
	}
	
}
int main(){
	double p = 1000000;
	int n = 6;
	vector<quatban> d = {{"toshiba", "do", 200000}, 
						 {"electrolux", "xanh", 250000},
						 {"panasonic", "xanh", 250000},
						 {"thongnhat", "xam", 100000},
						 {"hitachi", "ghi", 300000},
						 {"vinawind", "xanh", 250000},};
	int q = 0;
	vector<quatban> t;
	F3(p,d,q,t);
	HienThiKetQua (p,q,t);
}