#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
struct CongViec {
    string macongviec;
    string thoigianbatdau;
    double thoigianthuchien;
};
void showA1 (CongViec a) {
    cout << setw(7) << a.macongviec << setw(20) << a.thoigianbatdau << setw(20) << a.thoigianthuchien << "\n";
}
void A1(vector<CongViec> c, int n, int i) {
    if (i == 0) showA1(c[i]);
    else {
        showA1(c[i]);
        A1(c, n, i-1);
    }
}
int A2(vector<CongViec> c, int n, int l, int r, vector<CongViec> &cc) {
    if (l >= r) {
        if (c[l].thoigianthuchien <= 0.5) {
            cc.push_back(c[l]);
            return 1;
        }
        else return 0;
    }
    else {
        int m = l-(l-r)/2;
        int countLeft = A2(c, n, l, m, cc);
        int countRight = A2(c, n, m+1, r, cc);
        int res = countLeft + countRight;
        return res;
    }
}

void showA3(vector<CongViec> c, int n, vector<string> L, int x[]) {
    for (int i = 1; i<= n; i++) {
        cout << L[x[i]-1] << " - " << c[i-1].macongviec << "     ";
    }
    cout << "\n";
}
void next_conf(int x[], int i, int n) {
    int j = n;
    while (x[i] > x[j]) j--;
    swap(x[i], x[j]);
    i++;j=n;
    while (i < j){
        swap(x[i], x[j]);
        i++;
        j--;
    }
}
void A3 (vector<CongViec> c, int n, vector<string> L) {
    int x[n+1];
    for (int i = 1; i<=n; i++) x[i] = i;
    int i, cach = 0;
    do {
        cach++;
        cout << "Phuong an " << cach << ": ";
        showA3(c,n,L,x);
        i = n-1;
        while (i > 0 && x[i] > x[i+1]) i--;
        if (i > 0) next_conf(x, i, n);
    } while (i > 0);
}

int main() {
    int n = 6;
    vector<CongViec> c = {{"CV001", "7h10p", 0.5},
                          {"CV002", "7h20p", 0.2},
                          {"CV003", "7h50p", 0.1},
                          {"CV004", "8h00p", 1.0},
                          {"CV005", "8h30p", 1.5},
                          {"CV006", "9h10p", 1.2}};
    vector<string> L = {"Lan", "Nga", "Nam", "An", "Trung", "Huy"};
    cout << "--- Bieu dien thuat toan A1 ---\n";
    cout << "In danh sach c theo thu tu nguoc lai bang de quy:\n";
    cout << setw(12) << "Ma cong viec" << setw(20) << "Thoi gian bat dau" << setw(24) << "Thoi gian thuc hien" << "\n";
    A1(c, n, n-1);
    vector<CongViec> cc;            
    int resA2 = A2(c,n,0,n-1,cc); 
    cout << "--- Bieu dien thuat toan A2 ---\n";
    cout << "Dem so cong viec trong danh sach co thoi gian thuc hien nho hon 30 phut: ";
    if (resA2 == 0) cout << "Khong co";
    else {
        cout << "Co " << resA2 << " cong viec.\n";
        cout << setw(12) << "Ma cong viec" << setw(20) << "Thoi gian bat dau" << setw(24) << "Thoi gian thuc hien" << "\n";
        for (CongViec a: cc) showA1(a);
    }
    cout << "--- Bieu dien thuat toan A3 ---\n";
    A3(c, n, L);
}




// void nextC(int x[], int i) {
//     x[i]++;
//     i++;
//     while (i <= 2) {
//         x[i] = 0;
//         i++;
//     } 
// }
// void listc(){
//     int x[3] = {0};
//     int i;
//     do {
//         cout << x[1] << x[2] << '\n';
//         i = 2;
//         while (x[i] == 5) i--;
//         if (i > 0 && x[i] < 5) nextC(x, i);
//     } while (i > 0);
// }

// int main() {
//     listc();
// }