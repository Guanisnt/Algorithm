#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given the dimension of a sequence of matrices in an array arr[]
 * where the dimension of the ith matrix is (arr[i-1] * arr[i])
 */

/**
 * 2. guess
 *  - Last multiplication is between arr[i:k-1] and arr[k:j]
 * 1. subproblem
 *  - optimal evaluation of arr[i] ~ arr[j-1]
 * 3. recurrence
 *  - dp[i][j] = min(dp[i][k] + dp[k][j] + cost of multiplication of arr[i:k-1] and arr[k:j] for k in [i+1, j])
 * 4. topological order
 * - increasing substring size
 * 5. original problem
 * - dp(0, n);
 */

int findCost(vector<int>& arr) {
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
    int q = 0;
    for(int l=2; l<arr.size(); l++) {  // l is the length of the substring，從2開始是因為l=1的時候，dp[i][j] = 0
        for(int i=0; i<arr.size()-l; i++) {
            int j = i + l;  // j is the end of the substring
            dp[i][j] = INT_MAX;  // initialize the value to be the maximum value
            for(int k=i+1; k<j; k++) {
                q = dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j];  // recurrence
                if(q < dp[i][j]) {  // find the minimum cost
                    dp[i][j] = q;
                }
            }
        }
    } 
    return dp[0][arr.size()-1];  // dp(0, n)
}

int main() {
    vector<int> arr = {4, 2, 3, 5, 3};
    cout << findCost(arr) << endl;
}