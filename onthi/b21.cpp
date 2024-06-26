#include <bits/stdc++.h>
using namespace std;
bool F1 (vector<double> a, double C, int &D, double &M, vector<double> &get) {
    int i = 0;
    while (M + a[i] <= C) {
        M += a[i];
        get.push_back(a[i]);
        i++;
        D++;
    }
    if (D > 0) return true;
    return false;
}
int char_in_string (char c, string Q) {
    for (int i = Q.size()-1; i>=0; i--) {
        if (c == Q[i]) return i;
    }
    return -1;
}  
int boyer(string P, string Q) {
    int i = Q.size()-1;
    while (i < P.size()) {
        int x = Q.size()-1;
        while (x >= 0 && P[i] == Q[x]) {
            i--;
            x--;
        }
        if (x < 0) return i+1;
        else {
            int k = char_in_string(P[i], Q);
            if (k < 0) i+=Q.size();
            else i = i + Q.size() - k - 1;
        }
    }
    return -1;
}
int main() {
    int n = 8;
    vector<double> a = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
    double C = 10.99;
    string P = "mot con vit xoe ra 2 cai canh";
    string Q = "vit";
    double M = 0;
    int D = 0;
    vector<double> get;
    if (F1(a, C, D, M, get)) {
        cout << "D = " << D;
        cout << "\nM = " << M;
        cout << "\nCac phan tu da lay: ";
        for (double c: get) cout << c << " ";
    } else {
        cout << "Khong co phuong an.\n";
    }
    cout << "\nP = " << P;
    cout << "\nQ = " << Q;
    if (boyer(P,Q) > -1) cout << "\nQ la chuoi con cua P.";
    else cout << "\nQ khong phai chuoi con cua P.";  
    if (P.find(Q) != string::npos) cout << P.find(Q);
}