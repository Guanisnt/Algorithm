#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>    
using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;  // 初始時每個節點的 parent 是自己
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false;  // x 和 y 已在同一集合中
        if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else {  // rank 相同，隨便合併一邊並更新 rank
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

vector<tuple<int, int, long long>> kruskalMST(const vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    // 使用 priority_queue 儲存所有邊，按權重從小到大排序
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    for(int u=0; u<n; u++) {
        for(auto [v, w] : adj[u]) {
            pq.push({w, u, v});  // {weight, u, v}
        }
    }

    UnionFind uf(n);
    vector<tuple<int, int, long long>> mst;  // to store (u, v, weight) of MST
    while (!pq.empty()) {
        auto [w, u, v] = pq.top();
        pq.pop();
        if(uf.unite(u, v)) {  // 如果 u 和 v 不在同一個集合中，則把這條邊加入 MST
            mst.push_back({u, v, w});
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
    // 轉成 Adjacency List(練習用的)
    vector<vector<pair<int, int>>> adj(graph.size());
    for(int i=0; i<graph.size(); i++) {
        for(int j=0; j<graph[i].size(); j++) {
            if(graph[i][j] != 0) {
                adj[i].push_back({j, graph[i][j]});
            }
        }
    }
    vector<tuple<int, int, long long>> mst = kruskalMST(adj);  // (u, v, weight)
    cout << "Edges in the MST:" << endl;
    for (auto &[u, v, w] : mst) {
        cout << "Edge: " << u << " - " << v << " | Weight: " << w << endl;
    }

    int totalWeight = 0;
    for (auto &[u, v, w] : mst) {
        totalWeight += w;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}