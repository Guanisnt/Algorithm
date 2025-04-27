#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

int primMST(vector<vector<int>>& graph, int src) {
    vector<int> C1(graph.size(), src); // C1[i] stores the parent of vertex i in MST (每個點 i 所連過去的點)
    vector<int> C2(graph.size(), INT_MAX); // C2[i] stores the weight of edge (C1[i], i) in MST (目前到 i 的最小權重)
    vector<bool> inMST(graph.size(), false);  // 和 C1 搭配使用，標記哪些點已經在 MST 裡面了
    int totalWeight = 0;
    C2[src] = INT_MAX; // 自己到自己的權重設為 INF
    inMST[src] = true; // 起始點已經在 MST 裡面了
    int curNode = src;

    for(int k=0; k<graph.size()-1; k++) {  // MST 有 n-1 條邊
        // 跑過所有和 curNode 連接的點，更新 C2，並記錄 minIndex(C2中最小的 index)
        int minIndex = -1;
        int minValue = INT_MAX;
        for(int i=0; i<graph.size(); i++) {
            if(graph[curNode][i] != 0 && !inMST[i] && graph[curNode][i] < C2[i]) {  // 和 curNode 連接的點 i，且 i 不在 MST 裡面
                C2[i] = graph[curNode][i];
                C1[i] = curNode;
            }
            if(!inMST[i] && C2[i] < minValue) {  // 找出 C2 中最小的值和 index
                minValue = C2[i];
                minIndex = i;
            }
        }
        inMST[minIndex] = true;  // 將選中的節點 minIndex 加入 MST，並標記為已選擇
        C2[minIndex] = INT_MAX;  // 將 C2 中該節點的值設為 INF，表示這個節點已經被處理過了
        curNode = minIndex;  // 更新 curNode
        totalWeight += graph[C1[minIndex]][minIndex];
    }

    // 顯示 MST 的邊和權重
    for (int i = 0; i < graph.size(); i++) {
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

    int totalWeight = primMST(graph, 2);
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
