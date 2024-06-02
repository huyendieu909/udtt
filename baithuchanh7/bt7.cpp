#include <bits/stdc++.h>
using namespace std;
//    E A C B G C D Q P F K L
//  0 0 0 0 0 0 0 0 0 0 0 0 0
//B 0 0 0 0 1 1 1 1 1 1 1 1 1
//C 0 0 0 1 1 1 2 2 2 2 2 2 2
//G 0 0 0 1 1 2 2 2 2 2 2 2 2
//D 0 0 0 1 1 2 2 3 3 3 3 3 3
//F 0 0 0 1 1 2 2 3 3 3 4 4 4
//W 0 0 0 1 1 2 2 3 3 3 4 4 4
//P 0 0 0 1 1 2 2 3 3 4 4 4 4
//Q 0 0 0 1 1 2 2 3 4 4 4 4 4
// Q D G C
void sol (string T, string S, string &res) {
    int mat[S.size()+1][T.size()+1];
    for (int i = 0; i<=S.size(); i++) mat[i][0] = 0;
    for (int j = 0; j<=T.size(); j++) mat[0][j] = 0;
    for (int i=1; i<=S.size(); i++) {
        for (int j = 1; j<=T.size(); j++) {
            if (S[i-1] == T[j-1]) mat[i][j] = mat[i-1][j-1] + 1;
            else {
                mat[i][j] = (mat[i-1][j] > mat[i][j-1]) ? mat[i-1][j] : mat[i][j-1];
            }
        }
    } 
    int i = S.size(), j = T.size();
    while (mat[i][j] != 0) {
        if (S[i-1] == T[j-1]) res += S[i-1], i--, j--;
        else {
            if (mat[i-1][j] > mat[i][j-1]) i--;
            else j--;
        }
    }
    i = 0, j = res.size()-1;
    while (i < j) swap(res[i], res[j]), i++, j--;
    // for (int i = 0; i <= S.size(); i++) {
    //     for (int j = 0; j<= T.size(); j++) {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
int main() {
    string T = "EACBGCDQPFKL";
    string S = "BCGDFWPQ";
    int mat[S.size()+1][T.size()+1];
    string res = "";
    sol (T,S, res);
    cout << "\n" <<res;
}