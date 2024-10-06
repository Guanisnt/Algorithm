#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void QuickSort(vector<int>& a, int l, int r) {
    if(l >= r) return;
    int x = a[l];
    int i = l;
    int j = r;
    while(i < j) {
        while(i < j && x < a[j]) {
            j--;
        }
        if(i < j) swap(a[i++], a[j]);
        while(i < j && x > a[i]) {
            i++;
        }
        if(i < j) swap(a[i], a[j--]);
    }
    QuickSort(a, l, j-1);
    QuickSort(a, j+1, r);
}

int main() {
    vector<int> a = {3, 2, 1, 4, 5, 6, 6, 99, 101, 98, 102};
    QuickSort(a, 0, a.size()-1);
    for(int i=0; i<a.size(); i++) {
        cout << a[i] << " ";
    }
}