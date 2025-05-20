#include <iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

class Graph{
    public: 
        Graph(int vertices) : V(vertices){
            graph.resize(vertices);
        }

        void addEdge(int u, int v, int w){
            graph[u].push_back({v,w});
            graph[v].push_back({u, w});
            //if graph is directed, then remove above line
        }

        void dijkstra(int src);
    
    private:
        int V;
        vector<vector<pair<int, int>>> graph;
};

void Graph::dijkstra(int src)
{
    vector<int> distances(V, INT_MAX);
    distances[src] = 0;

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<>> min_heap;
    min_heap.push({0, src});

    while(!min_heap.empty()){
        int current_distance = min_heap.top().first;
        int u = min_heap.top().second;
        min_heap.pop();

        if(current_distance > distances[u]) continue;

        for (auto& [ v, weight] : graph[u])
        {
            int distance = current_distance + weight;
            if(distance < distances[v]){
                distances[v] = distance;
                min_heap.push({distance, v});
            }
        }
    }

    cout << "Vertex \t Distance from Source\n";
    for(int i = 0; i < V; ++i){
        cout << i << " \t " << distances[i];
    }
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 2, 7);
    g.addEdge(3, 2, 7);
    g.addEdge(4, 1, 1);
    g.addEdge(4, 2, 8);
    g.addEdge(4, 3, 2);

    g.dijkstra(0);    
    return 0;
}