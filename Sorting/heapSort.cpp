#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr[]. n is size of heap
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    // Build heap (rearrange array)
    for(int i=n/2-1; i>=0; i--) heapify(arr, n, i); // 從 inernal node 開始 heapify，bottom-up

    // One by one extract an element from heap
    for(int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]); // Move current root(maximum element) to end
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {4, 37, 26, 15, 48};
    heapSort(arr);
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}