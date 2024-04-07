#include <bits/stdc++.h>
using namespace std;
struct hang{
	int m;
	int v;
};
/* hàm này sắp xếp khối hàng theo khối lượng giảm dần */
void merge_sort (hang h[], int l, int r) {
	if (l < r) {
		int m = l - (l-r)/2;
		merge_sort(h, l, m);
		merge_sort(h, m+1, r);
		hang h_cop[100];
		for (int i = m; i>=l; i--) h_cop[i] = h[i];
		for (int j = m+1; j<=r; j++) h_cop[r+m+1-j] = h[j];
		int i = l, j = r;
		for (int k = l; k<=r; k++) {
			if (h_cop[i].m < h_cop[j].m) h[k] = h_cop[j], j--;
			else h[k] = h_cop[i], i++;
		}
	} 
}
vector<hang> xep_hang(int n, hang h[], int k, int &maxM, int &maxV) {
	merge_sort(h, 0, n-1); // sắp xếp hàng theo khối lượng giảm dần
	vector<hang> h_pick;
	int i = 0;
	while (i < n && k >= h[i].v) {
		h_pick.push_back(h[i]);
		k-=h[i].v;
		maxM += h[i].m;
		maxV += h[i].v;
		i++;
	}
	return h_pick;
}
int main() {
	system("chcp 65001");
	int n = 5;
	int k = 40; // thể tích thùng xe
//	int m[] = {9,7,3,6,1}; // khối lượng khối hàng
//	int v[] = {22,11,5,9,3}; // thể tích khối hàng
	hang h[] = {{9, 22}, {7, 11}, {3, 5}, {6, 9}, {1, 3}};
	cout << "Giả thiết có 5 khối hàng với khối lượng và thể tích lần lượt là: ";
	for (hang i: h) cout << "{"<<i.m << ", " << i.v << "}, ";
	cout << "\nXe của John có thể chở được tối đa " << k << " m3 hàng\n";
	int count = 0; // số kiện hàng xếp được
	int maxM = 0; // khối lượng lớn nhất xếp được
	int maxV = 0; // thể tích đã xếp;
	vector<hang> res = xep_hang(n, h, k, maxM, maxV);
	cout << "Số khối hàng xếp được theo tham lam: " << res.size();
	cout << "\nGồm các kiện hàng có khối lượng và thể tích lần lượt: ";
	for (hang k: res) cout << "{" << k.m << ", " << k.v << "} ";
	cout << "\nTổng khối lượng tối đa lấy được bằng tham lam: " << maxM;
}