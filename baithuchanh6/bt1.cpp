#include <bits/stdc++.h>
using namespace std;
bool F1 (string s) {
	int i=0, j = s.size()-1;
	while (i < j) {
		if (s[i] != s[j]) return false;
		i++;j--;
	}
	return true;
}
string F2 (string s, int k) {
	string ss = "";
	int i = 0;
	while (s[k+i] == s[k-i]) {
		ss += s[k+i];
		i++;
	}
	string res = "";
	for (int i = ss.size()-1; i>0; i--) res += ss[i];
	res += ss;
	return res;
}
int main() {
	system("chcp 65001");
	string s = "moldkgkdlnm";	
	if (F1(s)) cout << "s là xâu đối xứng.\n";
	else {
		cout << "s không đối xứng.\n";
		int k;
		cout << "Nhập k: ";
		cin >> k;
		cout << "Xâu con đối xứng dài nhất có tâm s[k] là: " << F2(s, k);
	} 
}