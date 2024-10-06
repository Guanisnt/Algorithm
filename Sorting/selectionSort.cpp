#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& a) {
    for(int i=0; i<a.size()-1; i++) {
        int minn = i;
        for(int j=i+1; j<a.size(); j++) {
            if(a[j] < a[minn]) minn = j;
        }
        swap(a[i], a[minn]);
    }
}

int main() {
    vector<int> a = {3, 2, 1, 4, 5, 6, 6, 99, 101, 98, 102};
    selectionSort(a);
    for(int i=0; i<a.size(); i++) {
        cout << a[i] << " ";
    }
}