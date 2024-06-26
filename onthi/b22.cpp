#include <bits/stdc++.h>
using namespace std;
bool thamlam (vector<double> a, double C, int &D, double &M, vector<double> &get){
    int i = a.size() - 1;
    while (i > -1 && M <= C) {
        M += a[i];
        D++;
        get.push_back(a[i]);
        i--;
    }
    if (M <= C) return false;
    else return true;
} 
int char_in_string (char c, string P) {
    for (int i = P.size() -1; i>-1; i--) {
        if (c == P[i]) return i;
    }
    return -1;
}
int boyer (string Q, string P) {
    int i = P.size() - 1;
    while (i < Q.size()) {
        int x = P.size() -1;
        while (x > -1 && P[x] == Q[i]) {
            i--;
            x--;
        }
        if (x < 0) return i+1;
        else {
            int k = char_in_string(Q[i], P);
            if (k < 0) i += P.size();
            else i = i + P.size() - k - 1;
        }
    }
    return -1;
}
int main() {
    int n = 8;
    vector<double> a = {1.3, 2.3, 3.1, 4.8, 5.2, 6.7, 7.9, 10.223};
    double C = 18.122, M = 0.0;
    int D = 0;
    vector<double> get;
    if (thamlam(a, C, D, M, get)) {
        cout << "D = " << D;
        cout << "\nM = " << M;
        cout << "\nCac gia tri da lay: ";
        for (double c: get) cout << c << " "; 
    }
    else {
        cout << "Khong co phuong an (lay het M van <= C).";
    }
    //3h43
    string Q = "ba thuong con vi con giong me.";
    string P = "con";
    int pos = boyer(Q, P);
    if (pos > -1) {
        cout << "\nTim thay P o vi tri " << pos << " trong Q";
    }
    else {
        cout << "\nP khong nam trong Q.";
    }
    //3h54
    cout << "\n" << Q.find(P);
}

// //3h22 3h27
