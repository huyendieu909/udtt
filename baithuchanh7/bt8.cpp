#include <bits/stdc++.h>
using namespace std;
struct hoithao {
    string chude;
    double thoigianbatdau;
    double thoigianketthuc;
};
bool comp (hoithao a, hoithao b) {
    return a.thoigianketthuc < b.thoigianketthuc;
}
void T1 (vector<hoithao> d, int &k, vector<hoithao> &s){
    sort(d.begin(), d.end(), comp);
    double last_schedule = 0;
    int i = 0;
    while (i < d.size()) {
        if (d[i].thoigianbatdau >= last_schedule) {
            s.push_back(d[i]);
            last_schedule = d[i].thoigianketthuc;
        }
        i++;
    }
    k = s.size();
} 
int main() {
    vector<hoithao> d = {{"Tim kiem viec lam", 7, 7.5},
                         {"Nang cao ki nang mem", 7.2, 8},
                         {"Cach viet CV tot", 7.5, 9.5},
                         {"Song cung AI", 8, 8.5},
                         {"Ki nang lam viec nhom", 9, 9.5}};
    int k;
    vector<hoithao> s;
    T1(d,k,s);
    cout << k << "\n";
    cout << setw(30) << "Chu de" << setw(20) << "Thoi gian bat dau" << setw(20) << "Thoi gian ket thuc" << "\n";
    for (hoithao i:s) {
        cout << setw(30) << i.chude << setw(20) << i.thoigianbatdau << setw(20) << i.thoigianketthuc << "\n";
    }
}