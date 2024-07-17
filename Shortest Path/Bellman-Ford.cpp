#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = vector<Edge>(E);
    return graph;
}

void BellmanFord(struct Graph* graph, int src) {
    // initialization
    int V = graph->V;
    int E = graph->E;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // relax all edges V-1 times
    for(int i=0; i<V-1; i++) {
        for(int j=0; j<E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if(dist[u] + weight < dist[v] && dist[u] != INT_MAX) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // check whether negative cycle exists or not
    for(int j=0; j<E; j++) {
        int u = graph->edge[j].src;
        int v = graph->edge[j].dest;
        int weight = graph->edge[j].weight;
        if(dist[u] + weight < dist[v] && dist[u] != INT_MAX) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }
    
    // if there is no negative cycle, print the shortest path
    for(int i=0; i<V; i++) {
        cout << i << " " << dist[i] << endl;
    }

    return;
}



int main() {
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
    
    BellmanFord(graph, 0);

    return 0;
}