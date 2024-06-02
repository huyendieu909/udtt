#include <bits/stdc++.h>
using namespace std;
struct laptop {
	string tenhang;
	string cauhinh;
	double giaban;
};
int char_in_string (char c, string p) {
	for (int i = p.size()-1; i >= 0; i--) {
		if (c == p[i]) return i;
	}
	return -1;
}
int F1 (string t, string p) {
	int i = p.size() - 1;
	while (i < t.size()) {
		int x = p.size() - 1;
		while (t[i] == p[x] && x >= 0) {
			i--;x--;
		}
		if (x < 0) return i+1;
		else {
			int k = char_in_string (t[i], p);
			if (k < 0) i+=p.size();
			else i = i + p.size() - k - 1;
		}
	}
	return -1;
}
int F3 (vector<laptop> d, string yc) {
	int r = 0;
	for (laptop i : d) if (F1(i.cauhinh, yc) >= 0) r++;
	return r;
}
int F4(vector<laptop> d, string yc2, vector<laptop> &t) {
	int s = 0;
	for (laptop i : d) {
		if (F1(i.cauhinh, yc2) >= 0) {
			t.push_back(i);
			s++;
		}
	}
	return s;
}
void showF4(int s, vector<laptop> t) {
	cout << "s = " << s <<'\n';
	if (s > 0) {
		cout << setw(18) << "Ten hang san xuat" << setw(40) << "Cau hinh" << setw(21) << "Gia ban" << "\n"; 
		for (laptop i : t) {
			cout << setw(18) << i.tenhang << setw(45) << i.cauhinh << setw(17) << setprecision(20) << i.giaban << "\n"; 
		}
	}	
}
int main() {
	vector<laptop> d = {{"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 15000000},
						{"ACER", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 2TB", 12000000},
						{"SAMSUNG", "CPU 2.9GHz upto 3.9GHz-RAM 8GB-SSD 512GB", 15000000},
						{"ASUS", "CPU 2.99GHz upto 4.2GHz-RAM 16GB-HDD 512GB", 17000000},
						{"DEL", "CPU 2.99GHz upto 4.2GHz-RAM 16GB-SSD 256GB", 16000000}};
	string yc1 = "RAM 16GB";
	string yc2 = "SSD";
	int r = F3(d, yc1);
	cout << "r = " << r << '\n';
	int s = 0;
	vector<laptop> t;
	s = F4(d, yc2, t);
	showF4(s,t);
}