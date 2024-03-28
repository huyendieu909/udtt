#include <bits/stdc++.h>
using namespace std;
struct thap{
	int	n;
	int a;
	int b;
	int c;
};
vector<thap> s;
void push(int n, int a, int b, int c) {
	thap t;
	t.n = n;
	t.a = a;
	t.b = b;
	t.c = c;
	s.push_back(t);
}
void solve(int so_vong) {
	thap t;
	push(so_vong,1,2,3);
	while (!s.empty()) {
		t = s.back();
		s.pop_back();
		if (t.n == 1) cout << "Chuyển 1 vòng từ cột " << t.a << " sang cột " << t.c << "\n";
		else {
			push(t.n-1, t.b, t.a, t.c);
			push(1, t.a, t.b, t.c);
			push(t.n-1, t.a, t.c, t.b);
		} 
	}
}
int main() {
	system("chcp 65001");
	cout << "Bài toán giả định có 3 cột với số vòng là n\n";
	cout << "Nhập n: ";
	int n;
	cin >> n;
	solve(n);
}