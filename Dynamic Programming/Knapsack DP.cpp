#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 1. guess
 * -  is the item i in the knapsack or not -> 2 choices
 * 2. subproblem
 * -  suffix i: of items & remaining capacity w(cannot exceed W)
 * 3. recurrence
 * -  dp[i][w] = max(dp[i+1][w], dp[i+1][w-weight[i]] + profit[i)
 * 4. topological order
 * -  decreasing suffix i
 * 5. original problem
 * -  dp[0][W]
 */

void knapsack(vector<int>& profit, vector<int>& weight, int W) {
    vector<vector<int>> dp(profit.size()+1, vector<int>(W+1, 0));
    for(int i=profit.size()-1; i>=0; i--) {
        for(int w=0; w<=W; w++) {
            if(w >= weight[i]) {
                dp[i][w] = max(dp[i+1][w], dp[i+1][w-weight[i]] + profit[i]);
            } else {
                dp[i][w] = dp[i+1][w];
            }
        }
    }
    cout << dp[0][W] << endl;
}

int main() {
    vector<int> profit = { 60, 100, 120 };
    vector<int> weight = { 10, 20, 30 };
    knapsack(profit, weight, 50);
    return 0;
}