#include <bits/stdc++.h>
using namespace std;
struct ChuyenBay {
    string sohieu;
    int giave;
    int soghengoi;
};
void show(ChuyenBay a, int i) {
    cout << setw(4) << i << setw(15) << a.sohieu << setw(15) << a.giave << setw(15) << a.soghengoi << "\n";
}
void showForA3(ChuyenBay a) {
    cout << setw(15) << a.sohieu << setw(15) << a.soghengoi << "\n";
}
// void mergeSort(vector<ChuyenBay> &a, int n, int l, int r) {
//     if (l < r) {
//         int m = l - (l - r)/2;
//         mergeSort(a, n, l, m);
//         mergeSort(a, n, m+1, r);
//         ChuyenBay b[n+1];
//         for (int i = m; i>=l; i--) b[i] = a[i];
//         for (int j = m+1; j<=r; j++) b[r+m+1-j] = a[j];
//         int i = l, j = r;
//         for (int k = l; k <= r; k++) {
//             if (b[i].giave < b[j].giave) a[k] = b[i], i++;
//             else a[k] = b[j], j--;
//         }
//     }
// }
void A1(vector<ChuyenBay> a, int i, vector<ChuyenBay> &b, int &count) {
    if (i == 0) {
        if (a[i].giave > 700000) b.push_back(a[i]), count++, show(a[i], count);
    }
    else {
        if (a[i].giave > 700000) b.push_back(a[i]), count++, show(a[i], count);
        A1(a, i-1, b, count);
    }
}
ChuyenBay min(ChuyenBay a, ChuyenBay b) {
    if (a.giave < b.giave) return a;
    return b; 
}
ChuyenBay A2(vector<ChuyenBay> a, int l, int r) {
    if (l >= r) {
        return a[l];    
    } else {
        int m = l-(l-r)/2;
        ChuyenBay minLeft = A2(a, l, m);
        ChuyenBay minRigt = A2(a, m+1, r);
        ChuyenBay res = min(minLeft, minRigt);
        return res;
    }
}
void A3(int i, vector<ChuyenBay> a, int n, int k, bool flag[], vector<ChuyenBay> &current_config, int &count) {
    if (current_config.size() == k) {
        count++;
        cout << "Cách " << count << "\n";
        for (ChuyenBay c:current_config) showForA3(c);
    }  
    for (int j = i; j < n; j++) {
        if (!flag[j]) {
            flag[j] = true;
            current_config.push_back(a[j]);
            A3(j+1, a, n,k,flag,current_config, count);
            current_config.pop_back();
            flag[j] = false;
        }
    }
}
int main() {
    system("chcp 65001");
    int n = 6, k = 4;
    vector<ChuyenBay> a = {{"VN001", 800000, 100},
                           {"VN002", 700000, 80},
                           {"VN003", 750000, 85},
                           {"VN004", 600000, 80},
                           {"VN005", 650000, 100},
                           {"VN006", 950000, 70}};
    vector<ChuyenBay> b;
    int count = 0;
    bool flag[n] = {false};
    cout << "===== Tất cả chuyển bay có giá vé trên 700000 =====\n";
    A1(a, n-1, b, count);
    cout << "\n--- Chuyến bay có giá vé thấp nhất ---\n";
    show(A2(a, 0, n-1), 1);
    vector<ChuyenBay> current_config;
    count = 0;
    cout << "\n--- Các cách chọn 4 chuyến bay từ dánh sách ---\n";
    A3(0, a, n, k, flag, current_config, count);
}