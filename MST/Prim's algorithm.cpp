#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
#define V 5

vector<tuple<int, int, long long>> primMST(vector<vector<int>>& graph) {
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    pq.push({0, 0, -1}); // {weight, starting vertex, parent}
    vector<bool> visited(V, false);
    vector<tuple<int, int, long long>> mst; // to store (u, v, weight) of MST
    while(!pq.empty()) {
        auto [w, u, parent] = pq.top();  // u 是當前節點, parent 是 u 的 parent
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        if(parent != -1) mst.push_back({parent, u, w});
        for(int v=0; v<V; v++) {  // 遍歷目前節點 u 的所有鄰居
            if(!visited[v] && graph[u][v] != 0) {
                pq.push({graph[u][v], v, u});  // 把 {weight, neighbor vertex, current vertex(parent)} 放進 priority queue
            }
        }
    }
    return mst;
}

int main() {
    vector<vector<int>> graph = 
                        { { 0, 2, 0, 6, 0 },
                          { 2, 0, 3, 8, 5 },
                          { 0, 3, 0, 0, 7 },
                          { 6, 8, 0, 0, 9 },
                          { 0, 5, 7, 9, 0 } };

    vector<tuple<int, int, long long>> mst = primMST(graph);  // (u, v, weight)
    
    cout << "Edges in the MST:" << endl;
    for (auto &[u, v, w] : mst) {
        cout << "Edge: " << u << " - " << v << " | Weight: " << w << endl;
    }

    int totalWeight = 0;
    for (auto &[u, v, w] : mst) {
        totalWeight += w;
    }
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
