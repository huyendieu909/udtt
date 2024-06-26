#include <bits/stdc++.h>
using namespace std;
int char_in_string (char c, string p) {
	for (int i=0; i<p.size(); i++) {
		if (c == p[i]) return i;
	}
	return -1;
}
int A3 (string s, string p, vector<int> &pos) {
	int i = p.size() - 1;
	while (i < s.size()) {
		int x = p.size()-1;
		while (p[x] == s[i]) {
			i--;x--;
		}
		if (x < 0) {
			int posOfP = i+1;
			pos.push_back(posOfP);
			i+= p.size() +1;
		} else {
			int k = char_in_string(s[i], p);
			if (k < 0) i += p.size();
			else i = i + p.size() - k - 1;
		}
	}
	return pos.size();
}
//void A4 (string s, string q, vector<int> &pos) {
//	for (int i = 0; i < pos.size(); i++) {
//		s.replace(pos[i], q.size(), q);
//		cout << s << "\n";
//	}
//}
string A4 (string s, string p, string q, vector<int> &pos) {
	string ss = "";
	if (pos.size() > 0){
		int i = 0, j = 0;
		while (j < s.size()) {
			if (j == pos[i]) {
				ss += q;
				j += p.size();
				i++;
			} else {
				ss+=s[j];
				j++;
			}
		}	
	}
	return ss;
}
int main() {
	string s = "nha co 5 child ruou, mot child vang, mot child vodka, bon child nep cai hoa vang";
	string p = "child";
	vector<int> pos;
	string q = "children";
	cout << s << "\n";
	cout << A3(s,p,pos)<< "\n";
	cout << A4(s,p,q,pos);
//	A4(s, q, pos);
//	cout << s;
}