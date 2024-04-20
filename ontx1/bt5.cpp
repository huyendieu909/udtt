#include <bits/stdc++.h>
using namespace std;
struct CongViec
{
    string macv;
    string thoigianbatdau;
    double thoigianthuchien;
};
void show(CongViec a){
    cout << setw(5) << a.macv << setw(23) << a.thoigianbatdau << setw(23) << a.thoigianthuchien << "\n";
}
void A1 (vector<CongViec> c, int i) {
    if (i == 0) show(c[i]);
    else {
        show(c[i]);
        A1(c, i-1);
    }
} 
int A2(vector<CongViec> c, int l, int r) {
    if (l >= r) {
        if (c[l].thoigianthuchien <= 0.5) return 1;
        return 0;
    } else {
        int m = l - (l-r)/2;
        int countLeft = A2(c, l, m);
        int countRight = A2(c, m+1, r);
        int res = countLeft + countRight;
        return res;
    }
}
void show(int x[], vector<CongViec> c, vector<string> L) {
    for (int i = 0; i<=5; i++) {
        cout << c[i].macv << " - " << L[x[i+1]-1] << "\n";
    }
}
void next_config(int x[], int i, int n){
    int j = n;
    while (j > i && x[j] < x[i]) j--;
    swap(x[i], x[j]);
    i++; j = n;
    while (i < j) {
        swap(x[i], x[j]);
        i++;
        j--;
    }
}
void A3(vector<CongViec> c, vector<string> L, int n, int &cach){
    int x[n+1];
    for (int i = 1; i<= n;i++) x[i] = i;
    int i;
    do {
        cach++;
        cout << "\nCách xếp " << cach << ":\n";
        show(x, c, L);
        i = n - 1; //12354
        while (i > 0 && x[i] > x[i+1]) i--;
        if (i > 0) next_config(x, i, n);
    } while (i > 0);
}
int main() {
    system("chcp 65001");
    int n = 6;
    vector<CongViec> c = {{"CV01", "7h10", 0.5},
                          {"CV02", "7h20", 0.35},
                          {"CV03", "7h30", 0.6},
                          {"CV04", "8h10", 1.5},
                          {"CV05", "9h10", 1.0},
                          {"CV06", "7h30", 0.4}};
    vector<string> L = {"Nam", "An", "Phương", "Quang", "Duy", "Long"};
    //a1
    cout << "--- Hiển thị danh sách c ngược lại bằng đệ quy ---\n";
    cout << setw(15) << "Mã công việc" << setw(33) << "Thời gian bắt đầu" << setw(33) << "Thời gian thực hiện" << "\n";
    A1(c, n-1);
    //a2
    cout << "\n--- Đếm số lượng công việc thực hiện dưới 0.5h bằng chia để trị ---\n";
    int count = A2(c, 0, n-1);
    if (count != 0) cout << "Có " << count << " công việc như vậy.\n";
    else cout << "Không có công việc nào như vậy.\n";
    //a3
    cout << "\n--- Tạo ds n công việc cho n nhân viên bằng phương pháp sinh --- \n";
    int cach = 0;
    A3(c, L, n, cach);
}