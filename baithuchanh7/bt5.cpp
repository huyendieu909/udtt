#include <bits/stdc++.h>
using namespace std;
int char_in_string (char c, string s){
	for (int i = 0; i < s.size(); i++) {
		if (c == s[i]) return i;
	}
	return -1;
}
int F1(string s, string p, vector<int> &pos) {
	int i = p.size()-1;
	while (i < s.size()) {
		int x = p.size()-1;
		while (s[i] == p[x] && x > -1) {
			i--; x--;
		}
		if (x < 0) {
			pos.push_back(i+1);
			i += p.size()+1;
		}
		else {
			int k = char_in_string(s[i], p);
			if (k < 0) i += p.size();
			else i = i + p.size() - k - 1;
		}
	}
	return pos.size();
}
//abdjfksj
//saf
string thay(string s, string p, string q, vector<int> pos) {
	int i = 0, j = 0;
	string ss ="";
	while (i < s.size()) {
		if (i == pos[j]){
			ss += q;
			i+=p.size();
			j++;
		}
		else {
			ss += s[i];
			i++;
		}
	}
	return ss;
}
int main() {
	string s = "ba thuong con vi con giong me.";
	cout << s << '\n';
	string p = "con";
	cout << p << '\n';
	vector<int> pos;
	cout << F1(s, p, pos);
	cout << "\n";
	cout <<	thay(s, p, "con trai", pos);
	
}