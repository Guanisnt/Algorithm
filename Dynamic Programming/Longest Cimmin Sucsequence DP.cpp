#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/**
 * 1. subproblem
 *  - LCS of str1[0:i] and str2[0:j]
 * 2. guess
 *  - Last character of str1 and str2 are the same or not
 * 3. recurrence
 *  - dp[i][j] = dp[i-1][j-1] + 1 if str1[i] == str2[j]
 *  - dp[i][j] = max(dp[i-1][j], dp[i][j-1]) if str1[i] != str2[j]
 * 4. topological order
 *  - increasing substring size
 * 5. original problem
 *  - dp(str1.size(), str2.size())
 */

int LCS(string str1, string str2) {
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
    for(int i=1; i<str1.size()+1; i++) {
        for(int j=1; j<str2.size()+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[str1.size()][str2.size()];
}

string findCommon(string str1, string str2) {
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
    for(int i=1; i<str1.size()+1; i++) {
        for(int j=1; j<str2.size()+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string res = "";
    int i = str1.size();
    int j = str2.size();
    while(i > 0 && j > 0) {
        if(str1[i-1] == str2[j-1]) {
            res = str1[i-1] + res;
            i--;
            j--;
        } else {
            if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    return res;
}

int main() {
    string str1 = "HIEROGLYPHOLOGY";
    string str2 = "MICHAELANGELO";
    cout << LCS(str1, str2) << endl;
    cout << findCommon(str1, str2) << endl;
}