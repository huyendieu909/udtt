#include <bits/stdc++.h>
using namespace std;
void show (vector<char> current_config) {
    for (char c:current_config) cout << c << " ";
    cout << '\n';
}
void next_config(int c[], int k, int i){
    c[i]++;
    i++;
    while (i <= k) {
        c[i] = c[i-1]+1;
        i++;
    }
}
void A3(vector<char> S, int k, vector<vector<char>> &list) {
    int n = S.size();
    int c[k+1] = {0};
    for (int i = 1; i<=k;i++) c[i] = i;
    int i;
    do {
        vector<char> current_config = {};
        for (int i=1; i<=k;i++) current_config.push_back(S[c[i]-1]);
        list.push_back(current_config);
        show(current_config);
        i = k;
        while (i > 0 && c[i] == n-k+i) i--;
        if (i > 0) next_config(c, k, i);
    } while (i > 0);
}
void A4(int t, vector<char> S, int k, bool flag[], vector<vector<char>> &list, vector<char> current_config){
    if (current_config.size() == k) show(current_config), list.push_back(current_config);
    for (int i = t; i<S.size(); i++) {
        if (!flag[i]) {
            flag[i] = true;
            current_config.push_back(S[i]);
            A4(i+1, S, k, flag, list, current_config);
            current_config.pop_back();
            flag[i] = false;
        }
    }
}
int main() {
    vector<char> S = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int k = 6;
    vector<vector<char>> list;
    A3(S, k, list);
    cout << "\n\n";
    bool flag[S.size()] = {false};
    vector<char> current_config;
    A4(0, S, k, flag, list, current_config);
}