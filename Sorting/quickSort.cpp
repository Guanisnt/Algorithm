#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void QuickSort(vector<int>& a, int l, int r) {
    if(l >= r) return;
    int x = a[l];
    int i = l, j = r;
    while(i < j) {
        while(i < j && a[j] >= x) j--;  // 從右往左找第一個小於x的數
        if(i < j) a[i++] = a[j];        // 把找到的數放到左邊
        while(i < j && a[i] <= x) i++;  // 從左往右找第一個大於x的數
        if(i < j) a[j--] = a[i];        // 把找到的數放到右邊
    }
    a[i] = x;  // 把x放到中間
    QuickSort(a, l, i-1);
    QuickSort(a, i+1, r);
}

int main() {
    vector<int> a = {3, 2, 1, 4, 5, 6, 6, 99, 101, 98, 102};
    QuickSort(a, 0, a.size()-1);
    for(int i=0; i<a.size(); i++) {
        cout << a[i] << " ";
    }
}