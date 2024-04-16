#include <bits/stdc++.h>
using namespace std;
void quickSort(int a[], int l, int r) {
    int i = l, j = r;
    int pivot = a[l + rand() % (r-l)];
    while (i <= j)
    {
        while (a[i] < pivot) ++i;
        while (a[j] > pivot) --j;
        if (i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (i < r) quickSort(a, i, r);
    if (j > l) quickSort(a, l, j);
}
int main() {
    srand(time(NULL));
    int a[] = {30,7,394,48,83,70};
    quickSort(a, 0, 5);
    for (int i: a) cout << i << " ";
}