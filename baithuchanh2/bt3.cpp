#include <bits/stdc++.h>
using namespace std;
void thapHN(int n, int a, int b, int c){
    if (n == 1) cout << "Chuyen vong tu cot " <<a<< " sang cot "<<c<<"\n";
    else {
        thapHN(n-1,a,c,b);
        thapHN(1,a,b,c);
        thapHN(n-1,b,a,c);
    }
}
int main(){
    thapHN(4,1,2,3);
}