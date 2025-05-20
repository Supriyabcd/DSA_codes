#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Graph{
    private:
        int V;
        vector<vector<pair<int,int>>> graph;
    
    public:
        Graph(int vertices) : V(vertices){
            graph.resize(vertices);
        }
        void addEdge(int u, int v, int w){
            graph[u].push_back({v,w});
            graph[v].push_back({u, w});
        }

        void primMST();
};

void Graph::primMST(){
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>minHeap;
    minHeap.push({0,0});
    key[0] = 0;

    while(!minHeap.empty()){
        int u = minHeap.top().second;
        minHeap.pop();
        inMST[u] = true;

        for(auto& neighbour : graph[u]){
            int v = neighbour.first;
            int w = neighbour.second;
            if(!inMST[v] && w < key[v]){
                key[v] = w;
                minHeap.push({key[v],v});
                parent[v] = u;
            }
        }
    }
    cout << "Edges in the constructed MST\n";
    for(int i = 1; i < V; ++i){
        cout << parent[i] << "--" << i << "==" << key[i] << endl;
    }
}
int main()
{
    int vertices, u, v, w, choice ;
    cout << "Enter no. of vertices : " ;
    cin >> vertices;

    Graph g(vertices); 
    while(true){
    cout << "To add edges, enter 1 else enter 0" << endl;
    cin >> choice;

    if(choice == 1 ){
        cout << "Enter values of u, v and w : ";
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    else break;
 }
    g.primMST();

    return 0;
}