#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

/**
 * 5-steps to DP:
 * --------------------------------
 * 1. Define subproblems
 *  - suffixes words i to n-1
 * 2. Guess (part of solution)
 *  - Where to start 2nd line
 * 3. Relate subproblem solutions
 *  - dp[i] = min(dp[j] + badness(i, j)) for all j > i
 * 4. Recursive and memorized OR build DP table bottom-up
 *  - topological order: i = n-1 to 0
 * 5. Solve original problem
 *  - dp[0]
 */

string formatText(const vector<string>& words, const int* result, const int* minCost) {
    int i = 0;
    int j;

    ostringstream builder;
    do {
        j = result[i];
        for (int k = i; k < j; ++k) {
            builder << words[k] << " ";
        }
        builder << "\n";
        i = j;
    } while (j < words.size());

    return builder.str();
}

void justify(vector<string>& words, int width) {
    int** cost = new int*[words.size()];
    for(int i=0; i<words.size(); i++) {cost[i] = new int[words.size()];}

    // Calculate cost of words[i] to words[j] in one line
    for(int i=0; i<words.size(); i++) {
        cost[i][i] = width - words[i].length();  // 對角線
        for(int j=i+1; j<words.size(); j++) {
            cost[i][j] = cost[i][j-1] - words[j].length() - 1;  // 對角線右邊的，-1是兩個字之間的空格
        }
    }
    // 把 cost 平方，超過 width 的部分變成無限大
    // 平方有點類似 cost function，越大的 cost 越不想選
    // panalty for extra spaces
    for(int i=0; i<words.size(); i++) {
        for(int j=i; j<words.size(); j++) {
            if(cost[i][j] < 0) {  // 超過 width
                cost[i][j] = INT_MAX;
            } else {
                cost[i][j] = cost[i][j] * cost[i][j];
            }
        }
    }

    // minCost from i to n-1 is found 
    // by trying j between i to n-1 and checking which one has min value
    int* minCost = new int[words.size()];
    int* result = new int[words.size()];  // 紀錄從哪裡開始換行
    for(int i=words.size()-1; i>=0; i--) {
        minCost[i] = cost[i][words.size()-1];
        result[i] = words.size();
        for(int j=words.size()-1; j>i; j--) {
            if(cost[i][j-1] == INT_MAX) continue;
            else if(minCost[j] + cost[i][j-1] < minCost[i]) {
                minCost[i] = minCost[j] + cost[i][j-1];
                result[i] = j;
            }
        }
    }

    cout << "Minimum cost is " << minCost[0] << endl;
    string formattedText = formatText(words, result, minCost);
    cout << formattedText;
}



int main() {
    vector<string> words = {"Guan", "Lin", "likes", "to", "code"};
    int width = 10;
    justify(words, width);
}