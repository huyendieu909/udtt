#include <bits/stdc++.h>
using namespace std;
int char_in_string(char c, string p) {
	for (int i = 0; i<p.size();i++) {
		if (c == p[i]) return i;
	}
	return -1;
}
bool F3 (string s, string p) {
	int dem = 0, i = p.size() - 1;
	while (i < s.size()) {
		int x = p.size()-1;
		while (s[i] == p[x] && x > -1){
			i--; x--;
		}
		if (x < 0) return true;
		else {
			int k = char_in_string(s[i], p);
			if (k < 0) i+=p.size();
			else i = i + p.size() - k - 1;
		}
	}
	return false;
}
void searchPInS (string s, string p, vector<int> &pos) {
	int i = p.size() - 1;
	while (i < s.size()) {
		int x = p.size()-1;
		while (s[i] == p[x] && x > -1){
			i--; x--;
		}
		if (x < 0) {
			int posOfP = i+1;
			pos.push_back(posOfP);
			i += p.size()+1;
		} 
		else {
			int k = char_in_string(s[i], p);
			if (k < 0) i+=p.size();
			else i = i + p.size() - k - 1;
		}
	}
}
string F4(string s, string p, string q, vector<int> &pos) {
	string ss = "";
	searchPInS(s, p, pos);
	if (pos.size() > 0) {
		int i = 0,j = 0;
		// 10 17
		while (j < s.size()) {
			if (j == pos[i]) {
				ss += q;
				i++;
				j+= p.size();
			}
			else {
				ss += s[j];
				j++;	
			} 
		}
	}
	return ss;
}
int main() {
	string s = "ba thuong con vi con giong me, ba cho con 1000, hom sau lai cho them 1000 nua.";
	string p = "1000";
	string q = "mot nghin dong";
	vector<int> pos;
	cout << F3(s, p) << '\n';

	cout << F4(s,p,q,pos);
	cout << "\n";
	for (int c : pos) cout << c << " " ;
}