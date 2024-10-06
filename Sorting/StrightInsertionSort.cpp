#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& v) {
    for(int i=1; i<v.size(); i++) {  // 0-based
        int j = i - 1;
        int curRound = v[i];
        while(curRound < v[j] && j >= 0) {
            v[j+1] = v[j];  // 往後移一格
            j--;
        }
        v[j+1] = curRound;  // 插入
    }
}

int main() {
    vector<int> v = {1, 5, 2, 8, 10, 11, 3, 6};
    insertionSort(v);
    for(int i : v) cout << i << " ";
}