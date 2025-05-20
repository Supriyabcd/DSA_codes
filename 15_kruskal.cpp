#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Graph{
    public:
        Graph(int vertices) : V(vertices){}
        void addEdge(int u, int v, int w){
            edges.push_back({w,{u,v}});
        }

        int find(int parent[], int i){
            if(parent[i] == i)
                return i;
            return find(parent, parent[i]);
        }

        void Union(int parent[], int rank[], int x, int y);
        void kruskalMST();
    private:
        int V;
        vector<pair<int,pair<int,int>>> edges;
};

void Graph::Union(int parent[], int rank[], int x, int y){
    int root_x = find(parent, x);
    int root_y = find(parent, y);

    if(rank[root_x] < rank[root_y]){
        parent[root_x] = root_y;
    } else if (rank[root_x] > rank[root_y]){
        parent[root_y] = root_x;
    } else {
        parent[root_y] = root_x;
        rank[root_x]++;
    }
}

void Graph::kruskalMST(){
    sort(edges.begin(), edges.end());
    vector<pair<int,pair<int,int>>> result;

    int* parent = new int[V];
    int* rank = new int[V];

    for(int i = 0; i < V; ++i){
        parent[i] = i;
        rank[i] = 0;
    }

    for(auto edge : edges)
    {
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;

        int x = find(parent, u);
        int y = find(parent, v);

        if (x != y){
            result.push_back({w,{u,v}});
            Union(parent, rank, x, y);
        }
    }

    cout << "Edges in the constructed MST\n";
    for(auto edge : result){
        cout << edge.second.first << "--" << edge.second.second << "==" << edge.first << endl;
    }
    delete[] parent;
    delete[] rank;
}

int main()
{
    int vertices, u, v, w, choice;
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

    g.kruskalMST();
    
    return 0;
}