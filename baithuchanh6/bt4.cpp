#include <bits/stdc++.h>
using namespace std;
//void Z(string s, int z[]) {
//	int l =0, r=0;
//	for (int i = 1; i<s.size();i++) {
//		if (i > r) {
//			l = r = i;
//			while (r < s.size() && s[r-l] == s[r]) r++;
//			z[i] = r-l; r--;
//		} else if (z[i-l] < r-i+1){
//			z[i] = z[i-l];
//		} else {
//			l = i;
//			while (r < s.size() && s[r-l] == s[r]) r++;
//			z[i] = r-l;r--;
//		}
//	}
//}
void Z(string s, int z[]) {
	int l = 0, r = 0;
	int n = s.size();
	//  
	//
	for (int i = 1; i < n; i++)
	   if (i > r)
	   {
	      l = r = i;
	      while (r < n && s[r] == s[r-l]) r++;
	      z[i] = r-l; r--;
	   }
	   else
	   {
	      int k = i - l;
	      if (z[k] < r - i + 1) z[i] = z[k];
	      else
	      {
	          l = i;
	          while (r < n && s[r] == s[r - l]) r++;
	          z[i] = r - l; r--;
	      }
	   }
}
string F1 (string s) {
	string ss = "";
	int i =0;
	while (s[i] != ' ' && i < s.size()){
		ss+=s[i];
		i++;
	}
	return ss;
}
string xoa(string s, string w, vector<int> pos) {
	string ss = "";
	if (pos.size() > 0) {
		int j = 0, i = 0;
		while (j < s.size()) {
			if (j == pos[i]) {
				j+=w.size();
				i++;
			}
			else {
				ss+=s[j];
				j++;
			}
		}	
	}
	return ss;
} 
int main() {
	string s = "ba thuong con vi con giong me me thuong con vi con giong 1 2 3 ba";
	string w = F1 (s);
	cout << w << "\n";
	
	string ss = w;
	ss += '$'; ss += s;
	int z[ss.size() +1];
	z[0] = ss.size();
	Z(ss, z);
	int sl = 0;
	vector<int> pos;
	for (int i = 1; i<ss.size(); i++) {
		if (z[i] == w.size()){
			sl++;
			pos.push_back(i-w.size()-1);	
		} 
	}
	for (int c: pos) cout << c << " ";
	cout << "\n";
	cout << sl << "\n";
	
	string sss = xoa(s,w,pos);
	cout << sss;
}