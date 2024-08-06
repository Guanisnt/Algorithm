#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getSum(vector<int>& BIT, int index) {
    int sum = 0;
    index = index + 1;
    while(index > 0) {
        sum += BIT[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(vector<int>& BIT, int n, int index, int val) {
    index = index + 1;  // index in BITree[] is 1 more than the index in arr[]
    while(index <= n) {
        BIT[index] += val;
        index += index & (-index);
    }
}

vector<int> constructBITree(vector<int> arr, int n) {
    vector<int> BIT(n+1, 0);

    // Store the actual values in BITree[] using update()
    for(int i=0; i<n; i++) {
        updateBIT(BIT, n, i, arr[i]);
    }

    return BIT;
}

int main() {
    vector<int> freq = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = freq.size();
    vector<int> BIT = constructBITree(freq, n);
    cout << "Sum of elements in arr[0..5] is "
        << getSum(BIT, 5); 

    // Let use test the update operation 
    freq[3] += 6; 
    updateBIT(BIT, n, 3, 6); //Update BIT for above change in arr[] 
  
    cout << "\nSum of elements in arr[0..5] after update is "
        << getSum(BIT, 5); 
  
    return 0; 
}