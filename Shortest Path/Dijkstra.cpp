#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

class Graph {
    int V;  // number of vertices
    vector<pair<int, int>> *adj;  // adjacency list
public:
    Graph(int V) {
        this->V = V;
        adj = new vector<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void dijkstra(int startPoint) {
        vector<int> dist(V, INT_MAX);  // 剛開始距離都是無限大
        dist[startPoint]= 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, startPoint});  // <距離, 點>
        while(!pq.empty()) {
            int u = pq.top().second;  // 把 pq 距離最小的點 extract 出來
            pq.pop();
            for(auto i=adj[u].begin(); i!=adj[u].end(); i++) {  // 所有和 u 相鄰的點
                int v = (*i).first;  // 點
                int w = (*i).second;  // weight
                if(dist[u] + w < dist[v]) {
                    // 更新距離
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        for(int i=0; i<V; i++) {
            cout << i << " " << dist[i] <<endl;
        }
    }
};

int main() {
    int V = 9;  // number of vertices
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.dijkstra(0);

    return 0;
}