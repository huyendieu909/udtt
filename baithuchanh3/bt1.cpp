#include <bits/stdc++.h>
using namespace std;
struct HocSinh {
    string ten;
    string hodem;
    int namsinh;
    string diachi;
};
HocSinh b[6];
int comp(HocSinh a, HocSinh b) {
    return a.ten.compare(b.ten);
}
void merge_Sort(HocSinh a[], int l, int r) {
    if (r > l){
        int m = l - (l-r)/2;
        merge_Sort(a, l, m);
        merge_Sort(a, m+1, r);
        for (int i = m; i >= l; i--) b[i] = a[i];
        for (int j = m+1; j <= r; j++) b[r+m+1-j] = a[j];
        int i = l, j = r;
        for (int k = l; k <= r; k++){
            if (comp(b[i], b[j]) < 0) a[k] = b[i], i++;
            else a[k] = b[j], j--;
        }
    }
}
int main() {
    HocSinh a[6]= {{"Linh", "Mã Tùng", 1998, "Mai Dịch"},
                        {"Quang", "Mai Văn", 1997, "La Mai"},
                        {"Văn", "Trần Trung", 1996, "Trung Trữ"},
                        {"Huy", "Lã Vương", 1995, "Ninh Giang"},
                        {"Hà", "Vũ Duy", 1999, "Bình Giang"},
                        {"Ninh", "Vũ Đình", 2000, "Khánh Minh"}};
    merge_Sort(a, 0, 5);
    cout << setw(4) << "Stt" << setw(30) << "Họ đệm" << setw(11) << "Tên" << setw(12) << "Năm sinh" << setw(20) << "Địa chỉ\n";
    for (int i = 0; i<6;i++) {
        cout << right << setw(3) << (i+1) << setw(25) << a[i].hodem << setw(11) << a[i].ten << setw(12) << a[i].namsinh << setw(20) << a[i].diachi << "\n";
    }
}