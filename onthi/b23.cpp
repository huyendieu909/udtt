#include<bits/stdc++.h>
using namespace std;
struct goihang {
    int m;
    int v;
};
bool thamlam (vector<goihang> a, double C, int &D, vector<goihang> &getD) {
    int i = 0;
    double v = 0;
    sort(a.begin(), a.end(), [](goihang a, goihang b){return a.v < b.v;});
    while (i < a.size() && v < C) {
        v+=a[i].v;
        getD.push_back(a[i]);
        i++;
        D++;
    }
    if (v == C) return true;
    else return false;
}
void qhd(vector<goihang> a, vector<goihang> &get, double &P, int M) {
    int mat[a.size()+1][M+1] = {0};
    for (int i = 0; i <= a.size(); i++) mat[i][0] = 0;
    for (int j = 0; j <= M; j++) mat[0][j] = 0;
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= M; j++) {
            if (j < a[i-1].m) mat[i][j] = mat[i-1][j];
            else mat[i][j] = max(mat[i-1][j], mat[i-1][j-a[i-1].m] + a[i-1].v);
        }
    }
    int i = a.size(), j = M; 
    P = mat[i][j];
    // cout << "\n";
    // for (int i = 1; i <= a.size(); i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << mat[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }
    while (mat[i][j] != 0) {
        while (mat[i-1][j] == mat[i][j]) i--;
        get.push_back(a[i-1]);
        j -= a[i-1].m;
    }
}
int main() {
    system("chcp 65001");
    int n = 8;
    vector<goihang> a = {{2,8} , {3,9}, {5,2}, {6,3}, {7,10}, {1,3}, {4,4}, {9,12}};
    int D = 0;
    double C = 8;
    int M = 17;
    vector<goihang> getD;
    if (thamlam(a, C, D, getD)) {
        cout << "D = " << D;
        cout << "\nCac goi hang da lay de duoc D: ";
        for (goihang i: getD) cout << i.m << " " << i.v << ", ";
    } else {
        cout << "Khong tim duoc phuong an nao bang tham lam de lay duoc gia tri bang C.";
    }
    vector<goihang> get;
    double P =0;
    qhd(a, get, P, M);
    cout << "\nP = " << P;
    cout << "\nGiá trị các gói hàng đã lấy để được P: ";
    for (goihang i: get) {
        cout << i.v << ", ";
    }
}
//9h46