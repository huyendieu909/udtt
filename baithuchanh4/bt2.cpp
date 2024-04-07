#include <bits/stdc++.h>
using namespace std;
int bottle_filling(int m, int n, vector<int> v){
    int s = 0;
    sort(v.begin(), v.end());
    int i = 0;
    while (m >= v[i] && i < n)  
    {
        s++;
        m-=v[i];
        i++;
    }
    return s;
}
int main (){
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(8);
    
}