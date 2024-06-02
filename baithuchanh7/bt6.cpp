#include <bits/stdc++.h>
using namespace std;
bool comp (string a, string b) {
    return a.size() > b.size();
}
string G (vector<string> &d, int k) {
    string s = "";
    sort(d.begin(), d.end(), comp);
    int i = 0;
    while (i < d.size() && k > 0) {
        if (k >= d[i].size()) {
            k -= d[i].size();
            s+=d[i];
        }
        i++;
    }
    return s;
}
int char_in_string(char c, string p) {
    for (int i= p.size()-1; i>=0; i--) if (c == p[i]) return i;
    return -1;
}
bool boyer(string s, string p) {
    int i = p.size() -1;
    while (i < s.size()) {
        int x = p.size() -1;
        while (s[i] == p[x] && x >= 0) i--, x--;
        if (x < 0) return true;
        else {
            int k = char_in_string(s[i], p);
            if (k < 0) i += p.size();
            else i = i + p.size() - k - 1; 
        }
    }
    return false;
}
int F1 (vector<string> d, string p, vector<string> &d1) {
    int s = 0;
    for (string i : d) if (boyer(i, p)) s++, d1.push_back(i);
    return s;
} 
void showF1 (int s, vector<string> d1) {
    cout << s << "\n";
    if (s > 0) {
        for (string i : d1) cout << i << "\n";
    }
}
void z_algo(vector<string> &d, int z[][100]) {
    //khởi tạo mảng z
    for (int i = 0; i<d.size(); i++) {
        for (int j = 1; j <d[i].size(); j++) {
            z[i][j] = 0;
        }
    }
    //here wegoooo
    for (int i = 1; i < d.size(); i++) {
        string s = d[0] + "$" + d[i];
        int l = 0, r = 0;
        z[i][0] = -1; 
        for (int j = 1; j < s.size(); j++) {
            if (j > r) {
                l = r = j;
                while (r < s.size() && s[r] == s[r-l]) r++;
                z[i][j]  = r - l; r--;
            } else if (z[i][j-l] < r - j + 1) z[i][j] = z[i][j-l];
            else {
                l = j;
                while (r < s.size() && s[r] == s[r-l]) r++;
                z[i][j] = r-l; r--;
            }
        } 
    }
}
void F2 (vector<string> d, int z[][100], vector<int> &y, vector<int> &y1) {
    z_algo(d,z);
    for (int i = 1; i < d.size(); i++) {
        int dem = 0;
        if (boyer(d[i], d[0])) {
            for (int j = 1; j < d[0].size() + 1 + d[i].size(); j++) if (z[i][j] == d[0].size()) dem++;
            y.push_back(i);
            y1.push_back(dem);
        }
    }
}
void showF2 (vector<string> d, vector<int> y, vector<int> y1) {
    cout << "\n Danh sach xau dang xet \n";
    for (string i : d) cout << i<< "\n";
    cout << "\n";
    cout << " xâu d[0] xuat hien trong cac xau \n";
    for (int i = 0; i<y.size(); i++) {
        cout << y[i] << " : " << y1[i] << " lan\n";
    }
}
int main() {
    vector<string> d = {{"Dont rush!"},
                        {"Dont rush! Repeat: Dont rush!"},
                        {"Slow! Dont rush!"},
                        {"Never gonna give the child up."},
                        {"Weekend has come, my child."}};
    vector<string> d_cpy = d;
    int k = 46;
    string p = G(d, k);
    cout << p << "\n";
    string yc1 = "child";
    vector<string> d1;
    int demchild = F1(d, yc1, d1);
    showF1(demchild, d1);
    int z[d.size()][100];
    vector<int> y;
    vector<int> y1;
    F2(d_cpy, z, y, y1);
    showF2(d_cpy, y, y1);
}