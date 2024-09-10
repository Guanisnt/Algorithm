#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int n = 4;  // 節點數量 (城市 1 到 4)
const int INF = 1000000;

// dist[i][j] 表示從城市 i 到城市 j 的距離，1-based 索引，可以用 Floyd-Warshall 求
int dist[n + 1][n + 1] = {
    { 0, 0, 0, 0, 0 },    // 0 行不使用，1-based 索引
    { 0, 0, 10, 15, 20 }, // 從城市 1 到其他城市的距離
    { 0, 10, 0, 25, 25 }, // 從城市 2 到其他城市的距離
    { 0, 15, 25, 0, 30 }, // 從城市 3 到其他城市的距離
    { 0, 20, 25, 30, 0 }, // 從城市 4 到其他城市的距離
};

// dp[i][mask] 表示從節點 i 出發遍歷 mask 表示的所有節點的最短路徑
// 1 << (n + 1) 是用來表示哪些城市被訪問過。例如，mask = 0110 表示城市 2 和城市 3 被訪問過。
vector<vector<int>> dp(n + 1, vector<int>((1 << (n + 1)), -1));

int tsp(int i, int mask) { // i 表示當前所在的城市，mask 表示哪些城市已經訪問過
    // 如果所有城市都已經訪問，回到原點
    if (mask == (1 << (n + 1)) - 2) { // 因為城市是 1-based，mask 的末位不需要
        return dist[i][1];  // 返回到起點城市 1
    }

    // 如果已經計算過該狀態，直接返回
    if (dp[i][mask] != -1) {
        return dp[i][mask];
    }

    int ans = INF;
    // 遍歷所有城市，選擇還沒有訪問的
    for (int k = 1; k <= n; ++k) {
        if (!(mask & (1 << k))) {  // 如果 k 還沒有被訪問過
            ans = min(ans, dist[i][k] + tsp(k, mask | (1 << k)));
        }
    }

    return dp[i][mask] = ans;
}

int main() {
    // 從城市 1 出發，初始訪問的城市只有城市 1
    int start_city = 1;
    int initial_mask = (1 << start_city);  // 設置城市 1 為已訪問
    cout << "最短路徑長度為: " << tsp(start_city, initial_mask) << endl;
    return 0;
}
