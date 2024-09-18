#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 99999
#define V 4
/**
 * Floyd-Warshall Algorithm
 * 1. subproblem:C_uv = weight of shortest path u → v whose intermediate vertices belongs to {1, 2, 3, …, k}
 * 2. Is k an intermediate vertex of shortest path u → v?
 * 3. Recurrence relation: C_uv = min(C_uv, C_uk + C_kv)
 * 4. Topological order: k → k-1 → … → 1
 * 5. original problem: C_uv = weight of shortest path u → v
 */

void printSolution(int dist[][V]) {
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

void floydWarshall(int dist[][V]) {
    for(int k=0; k<V; k++) {
        for(int u=0; u<V; u++) {
            for(int v=0; v<V; v++) {
                // if(dist[u][k] + dist[k][v] < dist[u][v]) {
                //     dist[u][v] = dist[u][k] + dist[k][v];
                // }
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }
    printSolution(dist);
}

int main() {
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

    floydWarshall(graph);
    return 0;
}