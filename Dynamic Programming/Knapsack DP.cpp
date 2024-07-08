#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Returns the value of maximum profit
int knapSackRec(int W, vector<int>& wt, vector<int>& val, int index, vector<vector<int>>& dp) {
    // base condition
    if (index < 0)
        return 0;
    if (dp[index][W] != -1)
        return dp[index][W];

    if (wt[index] > W) {

        // Store the value of function call
        // stack in table before return
        dp[index][W] = knapSackRec(W, wt, val, index - 1, dp);
        return dp[index][W];
    } else {
        // Store value in a table before return
        dp[index][W] = max(val[index]
                           + knapSackRec(W - wt[index], wt, val,
                                         index - 1, dp),
                       knapSackRec(W, wt, val, index - 1, dp));

        // Return value of table after storing
        return dp[index][W];
    }
}

int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return knapSackRec(W, wt, val, n - 1, dp);
}

int main() {
    vector<int> profit = { 60, 100, 120 };
    vector<int> weight = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n);
    return 0;
}