#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

int primMST(vector<vector<int>>& graph, int src) {
    vector<int> C1(graph.size(), -1); // C1[i] stores the parent of vertex i in MST (每個點 i 所連過去的點)
    vector<int> C2(graph.size(), INT_MAX); // C2[i] stores the weight of edge (C1[i], i) in MST (目前到 i 的最小權重)
    vector<bool> inMST(graph.size(), false);  // 和 C1 搭配使用，標記哪些點已經在 MST 裡面了
    int totalWeight = 0;
    C2[src] = 0; // 起始點的權重設為 0

    for (int i = 0; i < graph.size(); i++) {
        // 使用 min flag 紀錄 C2 中目前最小的 index
        int minIndex = -1;
        int minValue = INT_MAX;
        for (int j = 0; j < graph.size(); j++) {
            if (!inMST[j] && C2[j] < minValue) {
                minValue = C2[j];
                minIndex = j;
            }
        }

        // 如果無法選擇下一個節點，可能是圖不連通，直接返回
        if (minIndex == -1) {
            cout << "Graph is not connected!" << endl;
            return -1;
        }

        // 將選中的節點 minIndex 加入 MST，並標記為已選擇
        inMST[minIndex] = true;
        totalWeight += C2[minIndex];

        // 將 C2 中該節點的值設為 INF，表示這個節點已經被處理過了
        C2[minIndex] = INT_MAX;

        // 更新與 minIndex 連接的所有節點的 C2 值
        for (int v = 0; v < graph.size(); v++) {
            if (graph[minIndex][v] != 0 && !inMST[v] && graph[minIndex][v] < C2[v]) {
                C2[v] = graph[minIndex][v];
                C1[v] = minIndex;
            }
        }
    }

    // 顯示 MST 的邊和權重
    for (int i = 1; i < graph.size(); i++) {
        if (C1[i] != -1) {
            cout << C1[i] << " - " << i << " | Weight: " << graph[i][C1[i]] << endl;
        }
    }

    cout << "final C1: " << endl;
    for(int i=0; i<C1.size(); i++) {
        cout << C1[i] << " ";
    } cout << endl;

    cout << "final C2: " << endl;
    for(int i=0; i<C2.size(); i++) {
        cout << C2[i] << " ";
    } cout << endl;

    return totalWeight;
}

int main() {
    vector<vector<int>> graph = { { 0, 16, 4, 0, 2 },
                                  { 16, 0, 7, 0, 0 },
                                  { 4, 7, 0, 0, 7 },
                                  { 0, 0, 0, 0, 9 },
                                  { 2, 0, 7, 9, 0 } };

    int totalWeight = primMST(graph, 0);
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
