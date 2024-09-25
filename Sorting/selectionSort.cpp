#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& a) {
    for(int i=0; i<a.size()-2; i++) {
        int minPos = i;
        for(int j=i+1; j<a.size()-1; j++) {
            if(a[j] < a[minPos]) minPos = j;
        }
        swap(a[i], a[minPos]);
    }
}

int main() {
    vector<int> a = {3, 2, 1, 4, 5, 6, 6, 99, 101, 98, 102};
    selectionSort(a);
    for(int i=0; i<a.size(); i++) {
        cout << a[i] << " ";
    }
}